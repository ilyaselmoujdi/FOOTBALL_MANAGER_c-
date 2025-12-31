#include "Team.h"
#include <iostream>


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"

int main() {
    Team team;
    team.initializeWithTestData();

    int choice;

    do {
        team.checkStars();
        
        std::cout << BLUE << "\n******** MAIN MENU ********\n" << RESET;
        std::cout << "1. Add a player\n";
        std::cout << "2. Add multiple players\n";
        std::cout << "3. Display all players\n";
        std::cout << "4. Modify a player\n";
        std::cout << "5. Remove a player\n";
        std::cout << "6. Search for a player\n";
        std::cout << "7. Statistics\n";
        std::cout << "0. Exit\n";
        std::cout << "*************************\n";
        std::cout << "Your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                team.addPlayer();
                break;
            case 2:
                team.addMultiplePlayers();
                break;
            case 3:
                team.displayPlayers();
                break;
            case 4:
                team.modifyPlayer();
                break;
            case 5:
                team.removePlayer();
                break;
            case 6:
                team.searchPlayer();
                break;
            case 7:
                team.displayStatistics();
                break;
            case 0:
                std::cout << RED << "Goodbye.\n" << RESET;
                break;
            default:
                std::cout << RED << "Invalid choice.\n" << RESET;
        }
    } while (choice != 0);

    return 0;
}
