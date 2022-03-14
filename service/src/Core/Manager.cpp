#include "Manager.hpp"
#include <iostream>

using namespace Prog3::Core;
using namespace Prog3::Core::Model;
using namespace Prog3::Api::Parser;
using namespace Prog3::Repository;
using namespace std;

Manager::Manager(ParserIf &givenParser, RepositoryIf &givenRepository)
    : parser(givenParser), repository(givenRepository) {
}

Manager::~Manager() {
}

std::string Manager::getApp() {
    App app = repository.getApp();

    return parser.convertToApiString(app);
}

std::string Manager::getLists() {
    std::vector<ReminderList> rLists = repository.getReminderLists();

    return parser.convertToApiString(rLists);
}

std::string Manager::getList(int listId) {
    std::optional<ReminderList> rList = repository.getReminderList(listId);
    if (rList) {
        return parser.convertToApiString(rList.value());
    } else {
        return parser.getEmptyResponseString();
    }
}

std::string Manager::postList(std::string request) {
    int const dummyId = -1;
    std::optional<ReminderList> parsedReminderListOptional = parser.convertListToModel(dummyId, request);
    if (false == parsedReminderListOptional.has_value()) {
        return parser.getEmptyResponseString();
    }

    ReminderList parsedReminderList = parsedReminderListOptional.value();

    std::optional<ReminderList> postedReminderList = repository.postReminderList(parsedReminderList.getName(), parsedReminderList.getPos());

    if (postedReminderList) {
        return parser.convertToApiString(postedReminderList.value());
    } else {
        return parser.getEmptyResponseString();
    }
}

std::string Manager::putList(int listId, std::string request) {
    std::optional<ReminderList> parsedReminderListOptional = parser.convertListToModel(listId, request);

    if (false == parsedReminderListOptional.has_value()) {
        return parser.getEmptyResponseString();
    }
    ReminderList rList = parsedReminderListOptional.value();
    std::optional<ReminderList> putReminderList = repository.putReminderList(listId, rList.getName(), rList.getPos());

    if (putReminderList) {
        return parser.convertToApiString(putReminderList.value());
    } else {
        return parser.getEmptyResponseString();
    }
}

void Manager::deleteList(int listId) {
    repository.deleteReminderList(listId);
}

std::string Manager::getReminders(int listId) {
    std::vector<Reminder> reminders = repository.getReminders(listId);

    return parser.convertToApiString(reminders);
}

std::string Manager::getReminder(int listId, int reminderId) {
    std::optional<Reminder> reminder = repository.getReminder(listId, reminderId);
    if (reminder) {
        return parser.convertToApiString(reminder.value());
    } else {
        return parser.getEmptyResponseString();
    }
}

std::string Manager::postReminder(int listId, std::string request) {
    int const dummyId = -1;
    std::optional parsedReminderOptional = parser.convertReminderToModel(dummyId, request);
    if (false == parsedReminderOptional.has_value()) {
        return parser.getEmptyResponseString();
    }

    Reminder reminder = parsedReminderOptional.value();
    std::optional<Reminder> postedReminder = repository.postReminder(listId, reminder.getTitle(), reminder.getPos(), reminder.getTimestamp(), reminder.getFlag());
    if (postedReminder) {
        return parser.convertToApiString(postedReminder.value());
    } else {
        return parser.getEmptyResponseString();
    }
}

std::string Manager::putReminder(int listId, int reminderId, std::string request) {
    std::optional parsedReminderOptional = parser.convertReminderToModel(reminderId, request);
    if (false == parsedReminderOptional.has_value()) {
        return parser.getEmptyResponseString();
    }

    Reminder reminder = parsedReminderOptional.value();
    std::optional<Reminder> putReminder = repository.putReminder(listId, reminderId, reminder.getTitle(), reminder.getPos(), reminder.getTimestamp(), reminder.getFlag());

    if (putReminder) {
        return parser.convertToApiString(putReminder.value());
    } else {
        return parser.getEmptyResponseString();
    }
}

void Manager::deleteReminder(int listId, int reminderId) {
    repository.deleteReminder(listId, reminderId);
}
