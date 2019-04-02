#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

ssize_t write_all(int file, char const *buffer, size_t count);
ssize_t read_textfile(char const *filename, size_t letters);
int create_file(char const *filename, char *text_content);

#endif
