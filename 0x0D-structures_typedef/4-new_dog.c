#include <stdlib.h>
#include "dog.h"

/**
 * _strdup - duplicate string to new memory
 * @str: string to copy
 *
 * Return: pointer to copy or NULLif str is NULL orif allocation fails
 */
char *_strdup(char *str)
{
	unsigned int len;
	char *copy;

	if (str == NULL)
		return (NULL);
	for (len = 0; str[len] != '\0'; len++)
		;
	copy = malloc(sizeof(*copy) * len + sizeof(*copy) * 1);
	if (copy == NULL)
		return (NULL);
	for (len = 0; str[len] != '\0'; len++)
		copy[len] = str[len];
	copy[len] = '\0';
	return (copy);
}

/**
 * new_dog - creates a new instance of struct dog
 * @name: new dog name
 * @age: new dog age
 * @owner: new dog owner
 *
 * Return: pointer to newly-allocated struct dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	char *copy;
	dog_t *ret;

	ret = malloc(sizeof(*ret));
	if (ret == NULL)
		return (NULL);
	ret->name = NULL;
	if (name != NULL)
	{
		copy = _strdup(name);
		if (copy == NULL)
		{
			free(ret);
			return (NULL);
		}
		ret->name = copy;
	}
	ret->owner = NULL;
	if (owner != NULL)
	{
		copy = _strdup(owner);
		if (copy == NULL)
		{
			free(ret->name);
			free(ret);
			return (NULL);
		}
		ret->owner = copy;
	}
	ret->age = age;
	return (ret);
}
