#include <vector>
#include "gameCharacter.h"

#ifndef ROOM_H
#define ROOM_H

struct room
{
    int row;
    int col;

    std::vector<GameCharacter> enemies;
};

#endif