#include <iostream>
#include "game.h"

int main()
{
    std::string name;
    std::cout << "Welcome to the dungeon! What is your name?\n";
    std::cin >> name;

    Dungeon dungeon;
    Player player = Player(name, 100, 10);
    Game game(&player, &dungeon);

    std::cout << "Good luck, " << name << "!\n\n";

    while (!game.isGameOver)
    {
        game.initiateRoomSquence();
    }

    return 0;
}