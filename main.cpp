#include <iostream>
#include "game.h"

int main()
{
    Dungeon dungeon;
    Player player = Player("Dakotah", 100, 10);
    Game game(&player, &dungeon);

    std::cout << "test1";
    return 0;
}