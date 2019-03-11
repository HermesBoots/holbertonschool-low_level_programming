#include "dog.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

/**
 * init_dog - initializes a struct dog with given values
 * @d: pointer to struct dog
 * @name: value for name member
 * @age: value for age member
 * @owner: value for owner member
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;
	d->name = name;
	d->age = age;
	d->owner = owner;
}
