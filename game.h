#include "dungeon.h"
#include "player.h"

#ifndef GAME_H
#define GAME_H

class Game
{
private:
    Dungeon *dungeon;
    Player *player;

public:
    bool isGameOver;

    Game(Player *, Dungeon *);
};

#endif