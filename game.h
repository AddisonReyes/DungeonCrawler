#include "dungeon.h"
#include "player.h"

#include <vector>

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

    std::vector<std::string> getMovementActions();
    void printActions(std::vector<std::string>);
    void handleMovementActions();
    void initiateRoomSquence();
    void handleEnemyActions();
    void handleItemActions();
    void engageInCombat();
};

#endif