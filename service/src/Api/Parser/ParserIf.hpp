#pragma once
#include "./Core/Model/App.hpp"
#include <optional>

namespace Prog3 {
namespace Api {
namespace Parser {

class ParserIf {
  public:
    virtual ~ParserIf() {}

    virtual std::string getEmptyResponseString() = 0;
    virtual std::string convertToApiString(Prog3::Core::Model::App &app) = 0;
    virtual std::string convertToApiString(Prog3::Core::Model::ReminderList &list) = 0;
    virtual std::string convertToApiString(std::vector<Prog3::Core::Model::ReminderList> &lists) = 0;

    virtual std::string convertToApiString(Prog3::Core::Model::Reminder &reminder) = 0;
    virtual std::string convertToApiString(std::vector<Prog3::Core::Model::Reminder> &reminders) = 0;

    virtual std::optional<Prog3::Core::Model::ReminderList> convertListToModel(int listId, std::string &request) = 0;
    virtual std::optional<Prog3::Core::Model::Reminder> convertReminderToModel(int reminderId, std::string &request) = 0;
};

} // namespace Parser
} // namespace Api
} // namespace Prog3
