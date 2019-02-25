#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

int _putchar(char c);
char *_memset(char *buff, char val, unsigned int count);
char *_memcpy(char *dest, char *src, unsigned int count);
char *_strchr(char *str, char c);
unsigned int _strspn(char *str, char *accept);
char *_strpbrk(char *str, char *accept);
char *_strstr(char *haystack, char *needle);
void print_chessboard(char (*a)[8]);
void print_diagsums(int *arr, int size);

#endif
