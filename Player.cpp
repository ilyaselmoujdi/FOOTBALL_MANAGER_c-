#include "Player.h"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"

Player::Player() 
    : id(0), fullName(""), shirtNumber(0), position(""), 
      age(0), goals(0), registrationDate(""), status(""), isStar(false) {}

Player::Player(int id, const std::string& name, int shirt, const std::string& pos,
               int playerAge, int playerGoals, const std::string& regDate, const std::string& playerStatus)
    : id(id), fullName(name), shirtNumber(shirt), position(pos),
      age(playerAge), goals(playerGoals), registrationDate(regDate), status(playerStatus), isStar(false) {}

int Player::getId() const {
    return id;
}

std::string Player::getFullName() const {
    return fullName;
}

int Player::getShirtNumber() const {
    return shirtNumber;
}

std::string Player::getPosition() const {
    return position;
}

int Player::getAge() const {
    return age;
}

int Player::getGoals() const {
    return goals;
}

std::string Player::getRegistrationDate() const {
    return registrationDate;
}

std::string Player::getStatus() const {
    return status;
}

bool Player::getIsStar() const {
    return isStar;
}

void Player::setFullName(const std::string& name) {
    fullName = name;
}

void Player::setPosition(const std::string& pos) {
    position = pos;
}

void Player::setAge(int playerAge) {
    age = playerAge;
}

void Player::setGoals(int playerGoals) {
    goals = playerGoals;
}

void Player::setStatus(const std::string& playerStatus) {
    status = playerStatus;
}

void Player::setIsStar(bool star) {
    isStar = star;
}

void Player::display() const {
    std::cout << "[" << id << "] " << fullName << " | " << age << " years | "
              << position << " | " << goals << " goals | Shirt " << shirtNumber
              << " | " << status << " | Registered: " << registrationDate;
    if (isStar) {
        std::cout << " ⭐";
    }
    std::cout << "\n";
}
