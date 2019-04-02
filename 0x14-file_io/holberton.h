#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <unistd.h>


ssize_t write_all(int file, char const *buffer, size_t count);
ssize_t read_textfile(char const *filename, size_t letters);
int create_file(char const *filename, char *text_content);
int append_text_to_file(char const *filename, char *text_content);
void open_files(int *source, char const *spath, int *dest, char const *dpath);
int copy_file(int source, int dest);
void close_files(int source, int dest);


#endif
