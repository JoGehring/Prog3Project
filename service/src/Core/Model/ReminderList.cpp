#include "ReminderList.hpp"

using namespace Prog3::Core::Model;

ReminderList::ReminderList(int id, std::string givenName, int givenPosition)
    : id(id), name(givenName), position(givenPosition) {}

int ReminderList::getId() const {
    return id;
}

std::string ReminderList::getName() const {
    return name;
}

int ReminderList::getPos() const {
    return position;
}

std::vector<Reminder> ReminderList::getReminders() const {
    return reminders;
}

void ReminderList::setID(int givenId) {
    id = givenId;
}

void ReminderList::setName(std::string givenName) {
    name = givenName;
}

void ReminderList::setPos(int givenPos) {
    position = givenPos;
}

void ReminderList::addReminder(Reminder &givenReminder) {
    reminders.push_back(givenReminder);
}
