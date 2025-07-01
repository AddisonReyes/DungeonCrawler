#include <vector>

#include "gameCharacter.h"
#include "item.h"

#ifndef ROOM_H
#define ROOM_H

struct room
{
    int row;
    int col;

    std::vector<GameCharacter> enemies;
    std::vector<item> items;
};

#endif