#ifndef TEAM_H
#define TEAM_H

#include "Player.h"
#include <vector>
#include <string>

class Team {
private:
    std::vector<Player> players;
    int nextId;
    static const int MAX_PLAYERS = 40;

    // Helper methods
    bool isValidName(const std::string& name) const;
    bool isValidAge(int age) const;
    bool isShirtNumberTaken(int shirtNumber) const;
    bool isValidDate(int day, int month, int year) const;
    std::string getPositionFromChoice(int choice) const;
    std::string getStatusFromChoice(int choice) const;

public:
    // Constructor
    Team();

    // Main operations
    void addPlayer();
    void addMultiplePlayers();
    void displayPlayers();
    void searchPlayer();
    void modifyPlayer();
    void removePlayer();
    void displayStatistics();
    void checkStars();

    // Utility methods
    int getPlayerCount() const;
    bool isFull() const;
    void initializeWithTestData();
};

#endif
