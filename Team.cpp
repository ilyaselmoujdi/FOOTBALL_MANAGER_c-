#include "Team.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

Team::Team() : nextId(1) {}

bool Team::isValidName(const std::string& name) const {
    for (char c : name) {
        if (std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool Team::isValidAge(int age) const {
    return age >= 15 && age <= 50;
}

bool Team::isShirtNumberTaken(int shirtNumber) const {
    for (const auto& player : players) {
        if (player.getShirtNumber() == shirtNumber) {
            return true;
        }
    }
    return false;
}

int daysInMonth(int month, int year) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return 29;
        }
    }
    return days[month];
}

bool Team::isValidDate(int day, int month, int year) const {
    if (year < 1999 || year > 2025) return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > daysInMonth(month, year)) return false;
    return true;
}

std::string Team::getPositionFromChoice(int choice) const {
    switch (choice) {
        case 1: return "Goalkeeper";
        case 2: return "Defender";
        case 3: return "Midfielder";
        case 4: return "Striker";
        default: return "";
    }
}

std::string Team::getStatusFromChoice(int choice) const {
    switch (choice) {
        case 1: return "Starter";
        case 2: return "Substitute";
        default: return "";
    }
}

void Team::addPlayer() {
    if (isFull()) {
        std::cout << RED << "Team is full.\n" << RESET;
        return;
    }

    std::string fullName;
    int age, shirtNumber, goals, day, month, year;
    int choice;
    bool valid;

    // Get player name
    do {
        valid = true;
        std::cout << CYAN << "Full name: " << RESET;
        std::getline(std::cin, fullName);
        if (fullName.empty()) {
            std::cout << RED << "Error: Name cannot be empty.\n" << RESET;
            valid = false;
        } else if (!isValidName(fullName)) {
            std::cout << RED << "Error: Name cannot contain numbers.\n" << RESET;
            valid = false;
        }
    } while (!valid);

    // Get age
    do {
        std::cout << CYAN << "Age (between 15 and 50): " << RESET;
        std::cin >> age;
        if (!isValidAge(age)) {
            std::cout << RED << "Error: Age must be between 15 and 50.\n" << RESET;
        }
    } while (!isValidAge(age));

    // Get shirt number
    do {
        std::cout << CYAN << "Shirt number: " << RESET;
        std::cin >> shirtNumber;
        if (isShirtNumberTaken(shirtNumber)) {
            std::cout << RED << "Error: Shirt number is already taken.\n" << RESET;
        }
    } while (isShirtNumberTaken(shirtNumber));

    // Get position
    do {
        std::cout << CYAN << "Choose position:\n" << RESET;
        std::cout << "1. Goalkeeper\n2. Defender\n3. Midfielder\n4. Striker\n";
        std::cout << "Your choice: ";
        std::cin >> choice;
        if (choice < 1 || choice > 4) {
            std::cout << RED << "Error: Invalid choice.\n" << RESET;
        }
    } while (choice < 1 || choice > 4);
    std::string position = getPositionFromChoice(choice);

    // Get status
    do {
        std::cout << CYAN << "Choose status:\n" << RESET;
        std::cout << "1. Starter\n2. Substitute\n";
        std::cout << "Your choice: ";
        std::cin >> choice;
        if (choice < 1 || choice > 2) {
            std::cout << RED << "Error: Invalid choice.\n" << RESET;
        }
    } while (choice < 1 || choice > 2);
    std::string status = getStatusFromChoice(choice);

    // Get goals
    std::cout << CYAN << "Number of goals: " << RESET;
    std::cin >> goals;

    // Get registration date
    do {
        std::cout << CYAN << "Registration date (dd/mm/yyyy): " << RESET;
        std::cin >> day;
        std::cin.ignore();
        char slash1, slash2;
        std::cin >> month >> slash1 >> year >> slash2;
        if (!isValidDate(day, month, year)) {
            std::cout << RED << "Error: Invalid date. Year must be between 1999 and 2025.\n" << RESET;
        }
    } while (!isValidDate(day, month, year));

    std::string dateStr = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);

    // Create and add player
    players.emplace_back(nextId++, fullName, shirtNumber, position, age, goals, dateStr, status);
    std::cout << GREEN << ">>> Player added successfully!\n" << RESET;
}

void Team::addMultiplePlayers() {
    int count;
    std::cout << "How many players do you want to add? ";
    std::cin >> count;
    std::cin.ignore();

    for (int i = 0; i < count; i++) {
        std::cout << YELLOW << "\n**** Player " << (i + 1) << " ****\n" << RESET;
        addPlayer();
    }
}

void Team::displayPlayers() {
    if (players.empty()) {
        std::cout << RED << "No players registered.\n" << RESET;
        return;
    }

    int choice;
    std::cout << MAGENTA << "\n**** Display Players ****\n" << RESET;
    std::cout << CYAN << "1. Sort by Name (alphabetical)\n";
    std::cout << "2. Sort by Age (ascending)\n";
    std::cout << "3. Display by Position\n";
    std::cout << "4. Display by Status\n";
    std::cout << "5. Display by Age Range\n";
    std::cout << "0. Return\n" << RESET;
    std::cout << "Your choice: ";
    std::cin >> choice;

    if (choice == 0) return;
    std::cin.ignore();

    switch (choice) {
        case 1: {
            // Sort by name
            std::sort(players.begin(), players.end(),
                [](const Player& a, const Player& b) {
                    return a.getFullName() < b.getFullName();
                });
            std::cout << GREEN << "\n--- Players List ---\n" << RESET;
            for (const auto& player : players) {
                player.display();
            }
            break;
        }
        case 2: {
            // Sort by age
            std::sort(players.begin(), players.end(),
                [](const Player& a, const Player& b) {
                    return a.getAge() < b.getAge();
                });
            std::cout << GREEN << "\n--- Players List ---\n" << RESET;
            for (const auto& player : players) {
                player.display();
            }
            break;
        }
        case 3: {
            std::string position;
            std::cout << "Enter position (Goalkeeper/Defender/Midfielder/Striker): ";
            std::getline(std::cin, position);
            std::cout << GREEN << "\n--- Players by Position: " << position << " ---\n" << RESET;
            bool found = false;
            for (const auto& player : players) {
                if (player.getPosition() == position) {
                    player.display();
                    found = true;
                }
            }
            if (!found) {
                std::cout << RED << "No players found for this position.\n" << RESET;
            }
            break;
        }
        case 4: {
            std::string status;
            std::cout << "Enter status (Starter/Substitute): ";
            std::getline(std::cin, status);
            std::cout << GREEN << "\n--- Players by Status: " << status << " ---\n" << RESET;
            bool found = false;
            for (const auto& player : players) {
                if (player.getStatus() == status) {
                    player.display();
                    found = true;
                }
            }
            if (!found) {
                std::cout << RED << "No players found with this status.\n" << RESET;
            }
            break;
        }
        case 5: {
            int minAge, maxAge;
            std::cout << "Enter age range (min max): ";
            std::cin >> minAge >> maxAge;
            std::cout << GREEN << "\n--- Players aged " << minAge << " to " << maxAge << " ---\n" << RESET;
            bool found = false;
            for (const auto& player : players) {
                if (player.getAge() >= minAge && player.getAge() <= maxAge) {
                    player.display();
                    found = true;
                }
            }
            if (!found) {
                std::cout << RED << "No players found in this age range.\n" << RESET;
            }
            break;
        }
        default:
            std::cout << RED << "Invalid choice.\n" << RESET;
    }
}

void Team::searchPlayer() {
    int choice;
    std::cout << MAGENTA << "\n**** Search ****\n" << RESET;
    std::cout << "1. Search by ID\n2. Search by Name\n";
    std::cout << "Your choice: ";
    std::cin >> choice;
    std::cin.ignore();

    if (choice == 1) {
        int id;
        std::cout << "Enter ID: ";
        std::cin >> id;
        for (const auto& player : players) {
            if (player.getId() == id) {
                std::cout << GREEN << "Player found: " << player.getFullName() 
                         << " (" << player.getGoals() << " goals)\n" << RESET;
                return;
            }
        }
    } else if (choice == 2) {
        std::string name;
        std::cout << "Enter name: ";
        std::getline(std::cin, name);
        for (const auto& player : players) {
            if (player.getFullName() == name) {
                std::cout << GREEN << "Player found: " << player.getFullName() 
                         << " (" << player.getGoals() << " goals)\n" << RESET;
                return;
            }
        }
    }
    std::cout << RED << "No player found.\n" << RESET;
}

void Team::modifyPlayer() {
    int id;
    std::cout << "Enter ID of player to modify: ";
    std::cin >> id;
    std::cin.ignore();

    for (auto& player : players) {
        if (player.getId() == id) {
            std::string newPosition;
            int newAge, newGoals;
            
            std::cout << "New position: ";
            std::getline(std::cin, newPosition);
            std::cout << "New age: ";
            std::cin >> newAge;
            std::cout << "New goals: ";
            std::cin >> newGoals;

            player.setPosition(newPosition);
            player.setAge(newAge);
            player.setGoals(newGoals);
            std::cout << GREEN << "Player modified successfully.\n" << RESET;
            return;
        }
    }
    std::cout << RED << "Player not found.\n" << RESET;
}

void Team::removePlayer() {
    int id;
    std::cout << "Enter ID of player to remove: ";
    std::cin >> id;

    auto it = std::find_if(players.begin(), players.end(),
        [id](const Player& p) { return p.getId() == id; });

    if (it != players.end()) {
        players.erase(it);
        std::cout << GREEN << "Player removed successfully.\n" << RESET;
    } else {
        std::cout << RED << "Player not found.\n" << RESET;
    }
}

void Team::displayStatistics() {
    if (players.empty()) {
        std::cout << RED << "No players registered.\n" << RESET;
        return;
    }

    int choice;
    std::cout << MAGENTA << "\n**** Statistics ****\n" << RESET;
    std::cout << "1. Total number of players\n";
    std::cout << "2. Average age of players\n";
    std::cout << "3. Top scorer\n";
    std::cout << "4. Youngest and oldest player\n";
    std::cout << "0. Return\n";
    std::cout << "Your choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Total players: " << players.size() << "\n";
            break;
        case 2: {
            int totalAge = 0;
            for (const auto& player : players) {
                totalAge += player.getAge();
            }
            std::cout << std::fixed << std::setprecision(2)
                     << "Average age: " << (float)totalAge / players.size() << " years\n";
            break;
        }
        case 3: {
            auto topScorer = std::max_element(players.begin(), players.end(),
                [](const Player& a, const Player& b) {
                    return a.getGoals() < b.getGoals();
                });
            std::cout << "Top scorer: " << topScorer->getFullName() 
                     << " (" << topScorer->getGoals() << " goals)\n";
            break;
        }
        case 4: {
            auto youngest = std::min_element(players.begin(), players.end(),
                [](const Player& a, const Player& b) {
                    return a.getAge() < b.getAge();
                });
            auto oldest = std::max_element(players.begin(), players.end(),
                [](const Player& a, const Player& b) {
                    return a.getAge() < b.getAge();
                });
            std::cout << "Youngest: " << youngest->getFullName() << " (" 
                     << youngest->getAge() << " years)\n";
            std::cout << "Oldest: " << oldest->getFullName() << " (" 
                     << oldest->getAge() << " years)\n";
            break;
        }
        case 0:
            return;
        default:
            std::cout << RED << "Invalid choice.\n" << RESET;
    }
}

void Team::checkStars() {
    for (auto& player : players) {
        if (player.getGoals() >= 10 && !player.getIsStar()) {
            std::cout << YELLOW << ">>> " << player.getFullName() 
                     << " is a STAR with " << player.getGoals() << " goals!\n" << RESET;
            player.setIsStar(true);
        }
    }
}

int Team::getPlayerCount() const {
    return players.size();
}

bool Team::isFull() const {
    return players.size() >= MAX_PLAYERS;
}

void Team::initializeWithTestData() {
    players = {
        Player(1, "Lionel Messi", 10, "Striker", 36, 15, "12/09/2000", "Starter"),
        Player(2, "Cristiano Ronaldo", 7, "Striker", 39, 18, "10/08/2001", "Starter"),
        Player(3, "Kylian Mbappe", 11, "Striker", 26, 12, "05/07/2003", "Starter"),
        Player(4, "Manuel Neuer", 1, "Goalkeeper", 38, 0, "01/01/2004", "Starter"),
        Player(5, "Sergio Ramos", 4, "Defender", 35, 3, "15/03/2000", "Starter"),
        Player(6, "Luka Modric", 10, "Midfielder", 37, 5, "22/06/1999", "Starter"),
        Player(7, "Neymar Jr", 9, "Striker", 31, 14, "12/11/2001", "Starter"),
        Player(8, "Virgil van Dijk", 5, "Defender", 30, 2, "02/02/2002", "Starter"),
        Player(9, "Kevin De Bruyne", 17, "Midfielder", 31, 8, "19/04/2001", "Starter"),
        Player(10, "Mohamed Salah", 11, "Striker", 30, 13, "25/05/2003", "Starter"),
        Player(11, "Robert Lewandowski", 9, "Striker", 34, 20, "01/07/2000", "Starter"),
        Player(12, "Sadio Mane", 10, "Striker", 30, 11, "12/08/2002", "Starter"),
        Player(13, "Harry Kane", 9, "Striker", 29, 10, "15/09/2001", "Starter"),
        Player(14, "Alisson Becker", 1, "Goalkeeper", 30, 0, "30/01/2003", "Starter"),
        Player(15, "Joshua Kimmich", 6, "Midfielder", 27, 4, "08/02/2004", "Starter"),
        Player(16, "Trent Alexander-Arnold", 66, "Defender", 25, 1, "07/03/2005", "Starter"),
        Player(17, "Karim Benzema", 9, "Striker", 35, 17, "01/04/2000", "Starter"),
        Player(18, "Paulo Dybala", 21, "Striker", 29, 9, "11/05/2001", "Substitute"),
        Player(19, "Gianluigi Donnarumma", 99, "Goalkeeper", 23, 0, "15/06/2004", "Substitute"),
        Player(20, "Angel Di Maria", 11, "Midfielder", 34, 7, "20/07/2002", "Substitute")
    };
    nextId = 21;
}
