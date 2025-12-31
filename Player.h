#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

class Player {
private:
    int id;
    std::string fullName;
    int shirtNumber;
    std::string position;
    int age;
    int goals;
    std::string registrationDate;
    std::string status;
    bool isStar;

public:
    Player();
    Player(int id, const std::string& name, int shirt, const std::string& pos,
           int playerAge, int playerGoals, const std::string& regDate, const std::string& playerStatus);

    int getId() const;
    std::string getFullName() const;
    int getShirtNumber() const;
    std::string getPosition() const;
    int getAge() const;
    int getGoals() const;
    std::string getRegistrationDate() const;
    std::string getStatus() const;
    bool getIsStar() const;

    void setFullName(const std::string& name);
    void setPosition(const std::string& pos);
    void setAge(int playerAge);
    void setGoals(int playerGoals);
    void setStatus(const std::string& playerStatus);
    void setIsStar(bool star);


    void display() const;
};

#endif
