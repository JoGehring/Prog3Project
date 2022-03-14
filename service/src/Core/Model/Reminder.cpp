#include "Reminder.hpp"

using namespace Prog3::Core::Model;

Reminder::Reminder(int id, std::string givenTitle, int givenPosition, std::string givenTimestamp)
    : id(id), title(givenTitle), position(givenPosition), timestamp(givenTimestamp) {}

Reminder::Reminder(int id, std::string givenTitle, int givenPosition, std::string givenTimestamp, int givenFlag)
    : id(id), title(givenTitle), position(givenPosition), timestamp(givenTimestamp), flag(givenFlag) {}

int Reminder::getId() const {
    return id;
}

std::string Reminder::getTitle() const {
    return title;
}

int Reminder::getPos() const {
    return position;
}

std::string Reminder::getTimestamp() const {
    return timestamp;
}

int Reminder::getFlag() const {
    return flag;
}

void Reminder::setFlag(int flag) {
    flag = flag;
}

void Reminder::setID(int givenID) {
    id = givenID;
}

void Reminder::setTitle(std::string givenTitle) {
    title = givenTitle;
}

void Reminder::setPos(int givenPos) {
    position = givenPos;
}

void Reminder::setTimestamp(std::string givenTime) {
    timestamp = givenTime;
}
