#include "App.hpp"

using namespace Prog3::Core::Model;

App::App(std::string givenTitle) : title(givenTitle) {}

std::string App::getTitle() const {
    return title;
}

std::vector<ReminderList> &App::getReminderLists() {
    return lists;
}

void App::setReminderLists(std::vector<ReminderList> const &lists) {
    this->lists = lists;
}
