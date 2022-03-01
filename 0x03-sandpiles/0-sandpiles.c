#include "sandpiles.h"
#include <stdbool.h>

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * stabalize_pile - distributes sand until no cell has more than 3 grains
 * @grid1: input 3x3 sandpile to stabalize
 * @i: row coord of cell to topple
 * @j: column coord of cell to topple
 */
void stabalize_pile(int grid1[3][3], int i, int j)
{
	grid1[i][j] -= 4;

	if (i - 1 >= 0)
		grid1[i - 1][j]++;
	if (i + 1 < 3)
		grid1[i + 1][j]++;
	if (j - 1 >= 0)
		grid1[i][j - 1]++;
	if (j + 1 < 3)
		grid1[i][j + 1]++;
}

/**
 * should_topple - checks for stable grid and marks unstable cells
 * @grid: the grid to check
 * @topple_flags: 3x3 matrix of boolean flags
 *
 * Return: true if unstable, else false
 */
bool should_topple(int grid[3][3], bool topple_flags[3][3])
{
	bool topple = false;
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				topple = true;
				topple_flags[i][j] = true;
			}
			else
				topple_flags[i][j] = false;
		}
	return (topple);
}

/**
 * sandpiles_sum - sums two 3x3 sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	bool topple_flags[3][3] = {
		{false, false, false},
		{false, false, false},
		{false, false, false}
	};

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	while (should_topple(grid1, topple_flags))
	{
		printf("=\n");
		print_grid(grid1);

		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (topple_flags[i][j])
					stabalize_pile(grid1, i, j);
	}
}
