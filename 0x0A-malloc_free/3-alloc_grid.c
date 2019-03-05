#include <stdlib.h>

/**
 * alloc_grid - allocate and initialize to 0 a two-dimensional array
 * @width: size of first dimension
 * @height: size of second dimension
 *
 * Return: pointer to new array, NULL if allocation fails or if argument is < 1
 */
int **alloc_grid(int width, int height)
{
	int *grid __attribute__((unused)), **ret;
	int x, y;

	if (width < 1 || height < 1)
		return (NULL);
	ret = malloc(height * sizeof(int *));
	if (ret == NULL)
		return (NULL);
	/*
	 *grid = malloc(width * height * sizeof(int *));
	 *if (grid == NULL)
	 *{
	 *	free(ret);
	 *	return (NULL);
	 *}
	 */
	for (y = 0; y < height; y++)
	{
		ret[y] = malloc(width * sizeof(int));
		if (ret[y] == NULL)
		{
			for (height = 0; height < y; height++)
				free(ret[y]);
			free(ret);
		}
		for (x = 0; x < width; x++)
			ret[y][x] = 0;
	}
	return (ret);
}
