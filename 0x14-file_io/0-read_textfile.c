#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024


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
 * read_textfile - read some bytes from a text file and write to stdout
 * @filename: path fo file to read
 * @letters: number of bytes to read and write
 *
 * Return: number of letters read and written
 */
ssize_t read_textfile(char const *filename, size_t letters)
{
	char buffer[BUFFER_SIZE];
	int file;
	size_t ret = 0;
	ssize_t count, written;

	if (filename == NULL || letters == 0)
		return (0);
	file = open(filename, O_RDONLY);
	if (file < 0)
		return (0);
	do {
		count = read(file, buffer, BUFFER_SIZE);
		if (count < 1)
			break;
		count = ret + count < letters ? (size_t)count : letters - ret;
		written = write_all(STDOUT_FILENO, buffer, count);
		if (written < 0)
			break;
		ret += written;
	} while (ret < letters && written == count);
	if (count < 0 || written < 0)
		return (0);
	close(file);
	return (ret);
}
