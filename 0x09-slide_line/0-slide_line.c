#include "slide_line.h"

/**
 * reverse_array - reverses an array in pointer
 *
 * @array: array pointer to revers
 * @size: size of array to reverse
 */
void reverse_array(int *array, size_t size)
{
	size_t old, new, temp;

	for (old = 0, new = size - 1; old < size / 2; old++, new --)
	{
		temp = array[old];
		array[old] = array[new];
		array[new] = temp;
	}
}

/**
 * slide_line - Slide and combine integers like 2048
 *
 * @line: pointer to int array of size @size
 * @size: size of int array
 * @direction: 1/0 to indicate SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i, ii;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	/** if SLIDE_RIGHT, reverse array to apply same logic as SLIDE_LEFT */
	if (direction == SLIDE_RIGHT)
		reverse_array(line, size);
	/** remove zeros and shift everything to the left */
	for (i = 0, ii = 0; i < size; i++)
		if (line[i] != 0)
			line[ii++] = line[i];
	/** fill after last non-zero with zeros */
	while (ii < size)
		line[ii++] = 0;

	/** loop over array until first zero */
	for (i = 0; line[i] != 0; i++)
	{
		/** if next item == current, slide left */
		if (line[i] == line[i + 1])
		{
			line[i] *= 2;
			/** shift left or fill last item with 0 */
			for (ii = i + 1; ii < size; ii++)
				line[ii] = ii == size - 1 ? 0 : line[ii + 1];
		}
	}

	/** reverse array again if SLIDE_RIGHT */
	if (direction == SLIDE_RIGHT)
		reverse_array(line, size);

	return (1);
}
