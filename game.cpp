#include <iostream>
#
#include "game.h"

Game::Game(Player *_player, Dungeon *_dungeon) : player(_player), dungeon(_dungeon)
{
    isGameOver = false;

    dungeon->setUpDungeon();
    player->currentRoom = &dungeon->rooms[dungeon->rows - 1][dungeon->cols - 1];
}

void Game::initiateRoomSquence()
{
    if (!player->currentRoom->enemies.empty())
    {
        handleEnemyActions();
    }
    else
    {
        handleMovementActions();
    }
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

void Game::handleMovementActions()
{
    std::cout << "Where do you want to go next?\n";
    std::vector<std::string> actions = getMovementActions();
    printActions(actions);

    int input;
    std::cout << "Option: ";
    std::cin >> input;
    std::string chosenAction = actions[input - 1];

    int horizontalMovement = 0;
    int verticalMovement = 0;

    if (chosenAction == "Move left")
    {
        horizontalMovement = -1;
    }
    else if (chosenAction == "Move up")
    {
        verticalMovement = -1;
    }
    else if (chosenAction == "Move right")
    {
        horizontalMovement = 1;
    }
    else if (chosenAction == "Move down")
    {
        verticalMovement = 1;
    }

    int rMov = player->currentRoom->row + verticalMovement;
    int cMov = player->currentRoom->col + horizontalMovement;
    room *newRoom = &dungeon->rooms[rMov][cMov];
    player->moveToRoom(newRoom);

    std::cout << "You are now in the room "
              << newRoom->row << " " << newRoom->col
              << std::endl
              << std::endl;
}

void Game::handleEnemyActions()
{
    std::cout << "There is an enemy "
              << player->currentRoom->enemies[0].getName()
              << " in this room! What would you like to do?\n";
    std::vector<std::string> actions;
    actions.push_back("Engage enemy");
    actions.push_back("Retreat");
    printActions(actions);

    int input;
    std::cout << "Option: ";
    std::cin >> input;
    std::string chosenAction = actions[input - 1];

    if (chosenAction == "Engage enemy")
    {
        engageInCombat();
    }
    else
    {
        player->retreat();
    }

    std::cout << "You are now in the room "
              << std::endl
              << std::endl;
}

void Game::printActions(std::vector<std::string> actions)
{
    for (int i = 0; i < actions.size(); i++)
    {
        std::cout << i + 1 << ". " << actions[i] << std::endl;
    }
}

void Game::engageInCombat()
{
    GameCharacter *enemy = &player->currentRoom->enemies[0];
    while (true)
    {
        enemy->takeDamage(player->getDamage());
        std::cout << "You strike the " << enemy->getName()
                  << ", dealing " << player->getDamage() << " damage.\n";

        if (!enemy->checkIfAlive())
        {
            std::cout << "You have defeated the " << enemy->getName() << "!\n";
            player->currentRoom->enemies.clear();
            return;
        }

        player->takeDamage(enemy->getDamage());
        std::cout << "You take " << enemy->getDamage() << " damage."
                  << " You now have" << player->getHealth() << " health.\n";

        if (!player->checkIfAlive())
        {
            std::cout << "You have been defeated! Better luck next time!\n";
            isGameOver = true;
            return;
        }

        std::cout << "=What would you like to do?\n";
        std::vector<std::string> actions;
        actions.push_back("Engage enemy");
        actions.push_back("Retreat");
        printActions(actions);

        int input;
        std::cout << "Option: ";
        std::cin >> input;
        std::string chosenAction = actions[input - 1];

        if (chosenAction == "Engage enemy")
        {
            engageInCombat();
        }
        else
        {
            player->retreat();
        }
    }
}