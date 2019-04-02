#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "holberton.h"


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
 * create_file - create file with initial contents
 * @filename: name of file to create
 * @text_content: strint to write to file
 *
 * Return: 1 if success, -1 if failure
 */
int create_file(const char *filename, char *text_content)
{
	int file;
	mode_t const mode = S_IRUSR | S_IWUSR;
	size_t length = 0;
	ssize_t count = 0;

	if (filename == NULL)
		return (-1);
	file = open(filename, O_WRONLY | O_TRUNC | O_CREAT, mode);
	if (file < 0)
		return (-1);
	if (text_content != NULL)
	{
		for (length = 0; text_content[length] != '\0'; length++)
			;
		count = write_all(file, text_content, length);
	}
	close(file);
	if ((size_t)count != length)
		return (-1);
	return (1);
}
