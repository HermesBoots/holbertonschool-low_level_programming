#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - free a struct dog instance
 * @d: pointer to struct dog instance
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;
	free(d->name);
	free(d->owner);
	free(d);
}
