#pragma once

#include "ReminderList.hpp"
#include <iostream>
#include <string>
#include <vector>

namespace Prog3 {
namespace Core {
namespace Model {

class App {
  public:
    App(std::string givenTitle);
    ~App() {}

    std::string getTitle() const;

    std::vector<ReminderList> &getReminderLists();
    void setReminderLists(std::vector<ReminderList> const &lists);

  private:
    std::string title;
    std::vector<ReminderList> lists;
};

} // namespace Model
} // namespace Core
} // namespace Prog3
