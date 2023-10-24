#include <iostream>
#include <stdio.h>
#include <vector>

class Grid
{
public:
    std::vector<std::vector<int>> grid;
    int gridSize;
    Grid( int size )
    {
        printf("constucted\n");
        this->gridSize = size;
        this->grid.resize(size);
        for (int i = 0; i < size; i++)
        {
            this->grid[i].resize(size);
        }
    }

    void draw()
    {
        printf("passage inside draw\n");
        for (int i = 0; i < this->gridSize; i++)
        {
            for (int j = 0; j < this->gridSize; j++)
            {
                //printf("before this.grid: i=%d, j=%d\n", i, j);
                this->grid[i][j] = 0;
                printf("%d ", this->grid[i][j]);
            }
            printf("\n");
        }
    }

    void spawnBlock()
    {

    }

    void moveBlocks(char blocks)
    {

    }
};

int main()
{
    printf("start of Main\n");
    Grid grid(4);
    grid.draw();
    printf("end of Main\n");
}