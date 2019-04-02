#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define BUFFER_SIZE 1024


/**
 * open_files - try to open source and destination files
 * @source: source file descriptor
 * @spath: path to source file
 * @dest: destination file descriptor
 * @dpath: path to destination file
 */
void open_files(int *source, char const *spath, int *dest, char const *dpath)
{
	mode_t const mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	*source = open(spath, O_RDONLY);
	if (*source < 0)
	{
		dprintf(
			STDERR_FILENO,
			"Error: Can't read from file %s\n",
			spath
		);
		exit(98);
	}
	*dest = open(dpath, O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (*dest < 0)
	{
		dprintf(
			STDERR_FILENO,
			"Error: Can't write to %s\n",
			dpath
		);
		exit(99);
	}
}


/**
 * close_files - try to close source and destination files
 * @source: source file descriptor
 * @dest: destination file descriptor
 */
void close_files(int source, int dest)
{
	if (close(source) < 0)
	{
		dprintf(
			STDERR_FILENO,
			"Error: Can't close fd %d\n",
			source
		);
		exit(100);
	}
	if (close(dest) < 0)
	{
		dprintf(
			STDERR_FILENO,
			"Error: Can't close fd %d\n",
			dest
		);
		exit(100);
	}
}


/**
 * write_all - keep trying to write until it fails or all bytes written
 * @file: file descriptor
 * @buffer: buffer to write bytes from
 * @count: number of bytes to eventually write
 *
 * Return: number of bytes written
 */
ssize_t write_all(int file, char const *buffer, size_t count)
{
	size_t write_total = 0;
	ssize_t write_now;

	if (file < 0 || buffer == NULL || count < 1)
		return (-1);
	do {
		write_now = write(
			file,
			&buffer[write_total],
			count - write_total
		);
		write_total += write_now;
	} while (write_total < count && write_now > 0);
	if (write_now < 0)
		return (write_now);
	return (write_total);
}


/**
 * copy_file - copy text from one file to another
 * @source: source file descriptor
 * @dest: destination file descriptor
 *
 * Return: -1 on success, file that caused error on failure
 */
int copy_file(int source, int dest)
{
	char buffer[BUFFER_SIZE];
	ssize_t count, written;

	do {
		count = read(source, buffer, BUFFER_SIZE);
		written = write_all(dest, buffer, count);
	} while (count > 0 && written == count);
	if (count < 0)
		return (source);
	if (count != 0 && (written != count || written < 0))
		return (dest);
	return (-1);
}


/**
 * main - entry point, copies a file
 * @argc: number of command-line arguments
 * @argv: list of command-line arguments
 *
 * Return: error code
 */
int main(int argc, char *argv[])
{
	int dest, problem, source;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}
	open_files(&source, argv[1], &dest, argv[2]);
	problem = copy_file(source, dest);
	if (problem == source)
	{
		dprintf(
			STDERR_FILENO,
			"Error: Can't read from file %s\n",
			argv[1]
		);
		close(source);
		close(dest);
		return (98);
	}
	if (problem == dest)
	{
		dprintf(
			STDERR_FILENO,
			"Error: Can't write to %s\n",
			argv[2]
		);
		close(source);
		close(dest);
		return (99);
	}
	close_files(source, dest);
	return (0);
}
