#pragma once

#include "Reminder.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace Prog3 {
namespace Core {

namespace Model {

class ReminderList {
  public:
    ReminderList(int id, std::string givenName, int givenPosition);
    ~ReminderList(){};

    int getId() const;
    std::string getName() const;
    int getPos() const;
    std::vector<Reminder> getReminders() const;

    void setID(int givenId);
    void setName(std::string givenName);
    void setPos(int givenPos);
    void addReminder(Reminder &givenReminder);

  private:
    int id;
    std::string name;
    int position;
    std::vector<Reminder> reminders;
};
} // namespace Model
} // namespace Core
} // namespace Prog3
