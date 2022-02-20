#include <stdio.h>
#include <stdlib.h>

#include "menger.h"

/**
 * get_print_char - gets char to print based on row/col
 *
 * @row: current row in 2D grid
 * @col: current column in 2D grid
 *
 * Return: '#' if all divisions of row/col by 3 are divisible by 3
 */
char get_print_char(int row, int col)
{
	while (col || row)
	{
		if ((col % 3 == 1) && (row % 3 == 1))
			return (' ');
		col /= 3;
		row /= 3;
	}
	return ('#');
}

/**
 * menger - Draw a 2D Menger sponge
 *
 * @level: level of the Menger Sponge to draw
 */
void menger(int level)
{
	int dim = pow(3, level), row, col;

	if (level < 0)
		return;

	for (col = 0; col < dim; col++)
	{
		for (row = 0; row < dim; row++)
			putchar(get_print_char(row, col));
		putchar('\n');
	}
}
