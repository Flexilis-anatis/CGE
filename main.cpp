#include <vector>
#include <cstdint>
#include <iostream>
#include <string>

#include "source/screen.h"

class CGOL
{
    cge::Screen screen;

    typedef unsigned int Size;
    Size width, height;

    // Could also do a vector of positions that are alive, but I think the O(1) search time
    // looking for a cell may be quicker in the long run
    std::vector< std::vector<bool> > map;

    struct Cell {unsigned int x,y;};

    uint8_t countNeighbors(const Size x, const Size y)
    {
        uint8_t neighbors = 0;
        for (uint8_t i = -1; i < 2; i++)
            for (uint8_t j = -1; i < 2; j++)
                neighbors += ((i + j == 0) ? 0 : map[x+i][y+j]);
        return neighbors;
    }
    
public:
    CGOL(cge::Screen& screen, std::vector< std::vector<bool> > map = {},
         Size width = 10, Size height = 10)
    : screen(screen), width(width), height(height), map(map)
    {
        this->map.resize(height);
        for (Size x = 0; x < width; x++)
            this->map[x].resize(width);
    }


    void evolve()
    {
        std::vector<Cell> cellsToToggle;
        uint8_t neighbors;
        for (unsigned int x = 0; x < height; x++)
        {
            for (unsigned int y = 0; y < width; y++)
            {
                neighbors = countNeighbors(x, y);

                if (map[x][y]) screen.writenow(std::to_string(neighbors).c_str());
                
                if ((neighbors == 3 && !map[x][y]) || (neighbors != 2 && neighbors != 3 && map[x][y]))
                    cellsToToggle.push_back({x, y});
            }
        }

        for (const Cell& cell: cellsToToggle)
            map[cell.x][cell.y] = !map[cell.x][cell.y];
    }

    void display()
    {
        for (unsigned short x = 0; x < height; x++)
            for (unsigned short y = 0; y < width; y++)
                screen.write((map[x][y] ? "#" : "-"), {x, y});
        screen.display();
    }
};

int main()
{
    cge::Screen screen = cge::Screen();

    CGOL cgol(screen,
        {
            {true, true, false},
            {true}
        }
    );

    while (true)
    {
        cgol.display();
        cgol.evolve();
        getchar();
    }

    getchar();

    return 0;
}
