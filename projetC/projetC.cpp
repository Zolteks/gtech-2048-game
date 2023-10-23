#include <iostream>
#include <stdio.h>
#include <vector>

class Grid
{
public:
    Grid()
    {
        printf("constucted\n");
        std::vector<std::vector<int>> array;
        printf("[][][][]\n");
        printf("[][][][]\n");
        printf("[][][][]\n");
        printf("[][][][]\n");
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
    Grid grid;
    while (true)
    {
        //char response;
        //grid.moveBlocks(response);
        //grid.spawnBlock();
    }

}