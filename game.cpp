#include "game.h"

Game::Game(Player *_player, Dungeon *_dungeon) : player(_player), dungeon(_dungeon)
{
    isGameOver = false;

    dungeon->setUpDungeon();
    player->currentRoom = &dungeon->rooms[dungeon->rows - 1][dungeon->cols - 1];
}

std::vector<std::string> Game::getMovementActions()
{
    room *currentRoom = player->currentRoom;
    std::vector<std::string> actions;

    if (currentRoom->col > 0)
    {
        actions.push_back("Move left");
    }
    if (currentRoom->row > 0)
    {
        actions.push_back("Move up");
    }
    if (currentRoom->col < dungeon->cols - 1)
    {
        actions.push_back("Move right");
    }
    if (currentRoom->row < dungeon->rows - 1)
    {
        actions.push_back("Move down");
    }

    return actions;
}