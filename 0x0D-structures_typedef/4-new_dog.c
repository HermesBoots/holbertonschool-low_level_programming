#include <stdlib.h>
#include "dog.h"

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
	int len;

	ret = malloc(sizeof(*ret));
	if (ret == NULL)
		return (NULL);
	if (name != NULL)
	{
		for (len = 0; name[len] != '\0'; len++)
			;
		copy = malloc(sizeof(*name) * len + sizeof(*name) * 1);
		if (copy == NULL)
			return (NULL);
		for (len = 0; name[len] != '\0'; len++)
			copy[len] = name[len];
		copy[len] = '\0';
		name = copy;
	}
	ret->name = name;
	ret->age = age;
	if (owner != NULL)
	{
		for (len = 0; owner[len] != '\0'; len++)
			;
		copy = malloc(sizeof(*owner) * len + sizeof(*owner) * 1);
		if (copy == NULL)
			return (NULL);
		for (len = 0; owner[len] != '\0'; len++)
			copy[len] = owner[len];
		copy[len] = '\0';
		owner = copy;
	}
	ret->owner = owner;
	return (ret);
}
