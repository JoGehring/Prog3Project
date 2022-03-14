#define RAPIDJSON_ASSERT(x)

#include "JsonParser.hpp"
#include "../../Core/Exception/NotImplementedException.hpp"
#include "../../Core/Model/Reminder.hpp"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

using namespace Prog3::Api::Parser;
using namespace Prog3::Core::Model;
using namespace Prog3::Core::Exception;
using namespace rapidjson;
using namespace std;

bool JsonParser::isValidList(Document const &document) {
    bool isValid = true;

    if (document.HasParseError()) {
        isValid = false;
    }
    if (false == document["title"].IsString()) {
        isValid = false;
    }
    if (false == document["position"].IsInt()) {
        isValid = false;
    }

    return isValid;
}
bool JsonParser::isValidReminder(Document const &document) {

    bool isValid = true;

    if (document.HasParseError()) {
        isValid = false;
    }
    if (false == document["title"].IsString()) {
        isValid = false;
    }
    if (false == document["position"].IsInt()) {
        isValid = false;
    }
    if (false == document["timestamp"].IsString()) {
        isValid = false;
    }
    if (false == document["flag"].IsInt()) {
        isValid = false;
    }
    return isValid;
}

rapidjson::Value JsonParser::getJsonValueFromModel(Reminder const &reminder, rapidjson::Document::AllocatorType &allocator) {
    Value jsonReminder(kObjectType);

    jsonReminder.AddMember("id", reminder.getId(), allocator);
    jsonReminder.AddMember("title", Value(reminder.getTitle().c_str(), allocator), allocator);
    jsonReminder.AddMember("position", reminder.getPos(), allocator);
    jsonReminder.AddMember("timestamp", Value(reminder.getTimestamp().c_str(), allocator), allocator);
    jsonReminder.AddMember("flag", reminder.getFlag(), allocator);

    return jsonReminder;
}

rapidjson::Value JsonParser::getJsonValueFromModel(ReminderList const &list, rapidjson::Document::AllocatorType &allocator) {
    Value jsonList(kObjectType);

    jsonList.AddMember("id", list.getId(), allocator);
    jsonList.AddMember("title", Value(list.getName().c_str(), allocator), allocator);
    jsonList.AddMember("position", list.getPos(), allocator);

    Value jsonReminders(kArrayType);

    for (Reminder const &reminder : list.getReminders()) {
        Value jsonReminder = getJsonValueFromModel(reminder, allocator);
        jsonReminders.PushBack(jsonReminder, allocator);
    }

    jsonList.AddMember("reminders", jsonReminders, allocator);

    return jsonList;
}

string JsonParser::jsonValueToString(rapidjson::Value const &json) {
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    json.Accept(writer);

    return buffer.GetString();
}

string JsonParser::convertToApiString(App &app) {
    Document document(kObjectType);

    string result = "{\"title\":\"" + app.getTitle() + "\",\"lists\":";
    result += convertToApiString(app.getReminderLists());

    result += "}";

    return result;
}

string JsonParser::convertToApiString(ReminderList &list) {
    Document document(kObjectType);

    Value jsonList = getJsonValueFromModel(list, document.GetAllocator());
    return jsonValueToString(jsonList);
}

string JsonParser::convertToApiString(vector<ReminderList> &lists) {
    string result = EMPTY_JSON;

    if (!lists.empty()) {
        result = "[";
        Document document(kObjectType);
        string list = EMPTY_JSON;
        for (ReminderList &l : lists) {
            list = convertToApiString(l);
            result += list + ",";
        }
        result.pop_back();
        result += "]";
    }
    return result;
}

string JsonParser::convertToApiString(Reminder &reminder) {
    string result = EMPTY_JSON;
    Document document(kObjectType);

    Value jsonReminder = getJsonValueFromModel(reminder, document.GetAllocator());
    result = jsonValueToString(jsonReminder);
    return result;
}

string JsonParser::convertToApiString(vector<Reminder> &reminders) {
    if (reminders.empty())
        return EMPTY_JSON;
    else {
        string result = "[";
        string reminder = EMPTY_JSON;
        Document document(kObjectType);
        for (Reminder const i : reminders) {
            Value jsonReminder = getJsonValueFromModel(i, document.GetAllocator());
            reminder = jsonValueToString(jsonReminder);
            result += reminder + ",";
        }
        result.pop_back();
        result += "]";
        return result;
    }
}

optional<ReminderList> JsonParser::convertListToModel(int listId, string &request) {
    std::optional<ReminderList> result;
    Document document;
    document.Parse(request.c_str());

    if (true == isValidList(document)) {
        std::string title = document["title"].GetString();
        int position = document["position"].GetInt();
        result = ReminderList(listId, title, position);
    }
    return result;
}

optional<Reminder> JsonParser::convertReminderToModel(int reminderId, string &request) {
    std::optional<Reminder> result;

    Document document;
    document.Parse(request.c_str());

    if (true == isValidReminder(document)) {
        std::string title = document["title"].GetString();
        int position = document["position"].GetInt();
        std::string timestamp = document["timestamp"].GetString();
        int flag = document["flag"].GetInt();
        result = Reminder(reminderId, title, position, timestamp, flag);
    }
    return result;
}
