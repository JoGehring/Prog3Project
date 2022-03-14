#pragma once

#include "ParserIf.hpp"
#include "rapidjson/document.h"
#include <optional>

namespace Prog3 {
namespace Api {
namespace Parser {

class JsonParser : public ParserIf {
  private:
    static inline std::string const EMPTY_JSON = "{}";

    bool isValidList(rapidjson::Document const &document);
    bool isValidReminder(rapidjson::Document const &document);

    rapidjson::Value getJsonValueFromModel(Prog3::Core::Model::Reminder const &reminder, rapidjson::Document::AllocatorType &allocator);
    rapidjson::Value getJsonValueFromModel(Prog3::Core::Model::ReminderList const &list, rapidjson::Document::AllocatorType &allocator);

    std::string jsonValueToString(rapidjson::Value const &json);

  public:
    JsonParser(){};
    virtual ~JsonParser(){};

    virtual std::string convertToApiString(Prog3::Core::Model::App &app);

    virtual std::string convertToApiString(Prog3::Core::Model::ReminderList &list);
    virtual std::string convertToApiString(std::vector<Prog3::Core::Model::ReminderList> &lists);

    virtual std::string convertToApiString(Prog3::Core::Model::Reminder &reminder);
    virtual std::string convertToApiString(std::vector<Prog3::Core::Model::Reminder> &reminders);

    virtual std::optional<Prog3::Core::Model::ReminderList> convertListToModel(int listId, std::string &request);
    virtual std::optional<Prog3::Core::Model::Reminder> convertReminderToModel(int reminderId, std::string &request);

    virtual std::string getEmptyResponseString() {
        return JsonParser::EMPTY_JSON;
    }
};

} // namespace Parser
} // namespace Api
} // namespace Prog3
