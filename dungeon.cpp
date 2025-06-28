#include "dungeon.h"

void Dungeon::setUpDungeon()
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            room room;
            room.row = r;
            room.col = c;
            rooms[r][c] = room;
        }
    }
}