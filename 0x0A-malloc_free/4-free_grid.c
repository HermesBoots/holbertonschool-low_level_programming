#include <stdlib.h>

/**
 * free_grid - free a grid stored as two arrays, pointers and integers
 * @grid: grid to free
 * @height: number of columns in grid to free
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL || height < 1)
		return;
	for (i = 0; i < height; i++)
		free(grid[i]);
	free(grid);
}
