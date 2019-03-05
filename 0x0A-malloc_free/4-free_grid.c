#include <stdlib.h>

/**
 * free_grid - free a grid stored as two arrays, pointers and integers
 * @grid: grid to free
 * @height: number of columns in grid to free
 */
void free_grid(int **grid, int height)
{
	if (grid == NULL || height < 1)
		return;
	free(grid[0]);
	free(grid);
}
