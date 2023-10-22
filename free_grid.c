#include "shell.h"

/**
  * free_grid - program that frees memory allocated for a 2D grid of strings
  *
  * @grid: a pointer to the 2D grid of strings to be freed
  *
  * this function is responsible for freeing the memory allocated for a
  * two-dimensional grid of strings;
  * it takes the 'grid' as input and first determines its height by counting
  * the number of rows;
  * then, it iterates through each row and frees the memory for the individual
  * strings within that row;
  * finally, it frees the memory for the grid itself
  *
  * Return: nothing (void)
  */

void free_grid(char **grid)
{
	int i = 0;
	int height;

	while (grid[i])
		i++;

	height = i;

	for (i = 0; i < height; i++)
    {
        free(grid[i]);
    }
	free(grid);
}
