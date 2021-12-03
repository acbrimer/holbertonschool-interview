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
 */
void stabalize_pile(int grid1[3][3])
{
    int i, ii;
    bool topple = false;
    int sandpile[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    for (i = 0; i < 3; i++)
        for (ii = 0; ii < 3; ii++)
        {
            if (grid1[i][ii] < 4)
                sandpile[i][ii] += sandpile[i][ii];
            else if (grid1[i][ii] >= 4)
            {
                sandpile[i][ii] += grid1[i][ii] - 4;
                if (i > 0)
                    sandpile[i - 1][ii] += 1;
                if (ii > 0)
                    sandpile[i][ii - 1] += 1;
                if (i < 2)
                    sandpile[i + 1][ii] += 1;
                if (ii < 2)
                    sandpile[i][ii + 1] += 1;
            }
        }
    for (i = 0; i < 3; i++)
        for (ii = 0; ii < 3; ii++)
        {
            if (sandpile[i][ii] > 3)
                topple = true;
            grid1[i][ii] = sandpile[i][ii];
        }
    if (topple)
    {
        printf("=\n");
        print_grid(grid1);
        stabalize_pile(grid1);
    }
}

/**
 * sandpiles_sum - sums two 3x3 sandpiles
 * @grid1: first sandpile
 * @grid2: second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;
    bool topple = false;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] = grid1[i][j] + grid2[i][j];
            if (grid1[i][j] > 3)
                topple = true;
        }
    if (topple)
    {
        printf("=\n");
        print_grid(grid1);
        stabalize_pile(grid1);
    }
}
