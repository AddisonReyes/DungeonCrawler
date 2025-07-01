#include <iostream>
#include "game.h"

int main()
{
    Dungeon dungeon;
    Player player = Player("Dakotah", 100, 10);
    Game game(&player, &dungeon);

    while (!game.isGameOver)
    {
        game.initiateRoomSquence();
    }

    return 0;
}