#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char *av[])
{
    if (ac != 4)
        return 1;
    // init the main varibles
    int width = atoi(av[1]);
    int height = atoi(av[2]);
    int iter = atoi(av[3]);

    // allocation of 3D array + perimeter surrounding the 2D arrays
    char grid[2][height + 2][width + 2];

    // fill zeros on every cells of the 3D array
    for (int i = 0; i < 2; i++)
    {
        for (int h = 0; h < height + 2; h++)
        {
            for (int w = 0; w < width + 2; w++)
            {
                grid[i][h][w] = 0;
            }
        }
    }

    //reading from the standard input to apply the user command.
    char cmd;
    int pen = 0, x = 1, y = 1;
    while (read(0, &cmd, sizeof(cmd)) > 0)
    {
        if (cmd == 'x')
        {
            pen = !pen;
        }
        else if (cmd == 'w' && y > 1)
        {
            y--;
        }
        else if (cmd == 'a' && x > 1)
        {
            x--;
        }
        else if (cmd == 's' && y < height)
        {
            y++;
        }
        else if (cmd == 'd' && x < width)
        {
            x++;
        }
        if (pen)
        {
            grid[0][y][x] = 1;
        }
    }

    /*
        notes:
            # grid[iteration % 2][height][width]:
                - (iteration % 2) => means the index of the array we are expected to be in at tha end of program.
            
            # grid[iteration % 2][height][width]:
                - ((iteration + 1) % 2)) => means the symmetry of the array we are in now (iteration % 2).
    */


    // check the live and dies cells in every iteration.
    for (int i = 0; i < iter; i++)
    {
        for (int h = 1; h < height + 1; h++)
        {
            for (int w = 1; w < width + 1; w++)
            {
                int nb = 0;
                for (int x = -1; x <= 1; x++)
                {
                    for (int y = -1; y <= 1; y++)
                    {
                        if (!(x == 0 && y == 0))
                        {
                            nb += grid[i % 2][y + h][w + x];
                        }
                    }
                }
                if (grid[i % 2][h][w] == 1)
                {
                    if (nb == 2 || nb == 3)
                    {
                        grid[(i + 1) % 2][h][w] = 1;
                    }
                    else
                    {
                        grid[(i + 1) % 2][h][w] = 0;
                    }
                }
                else
                {
                    if (nb == 3)
                    {
                        grid[(i + 1) % 2][h][w] = 1;
                    }
                    else
                    {
                        grid[(i + 1) % 2][h][w] = 0;
                    }
                }
            }
        }
    }

    // display the last result on standard output.
    for (int h = 1; h <= height; h++)
    {
        for (int w = 1; w <= width; w++)
        {
            if (grid[iter % 2][h][w] == 1)
                putchar('0');
            else if (grid[iter % 2][h][w] == 0)
                putchar('.');
        }
        putchar('\n');
    }
    return 0;
}