#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

int _putchar(char c);
void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
unsigned int _strlen(char *str);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void error(void);
unsigned int isnumeric(char *str);
void print_int(char *str);
void bigadd(char *op1, unsigned int op2, unsigned int power, unsigned int len);
void bigmul(
		char *op1, unsigned int len1,
		char *op2, unsigned int len2,
		char *sum, unsigned int lens
);

#endif
