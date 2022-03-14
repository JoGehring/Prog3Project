#include "SQLiteRepository.hpp"
#include "Core/Exception/NotImplementedException.hpp"
#include <filesystem>
#include <iostream>

using namespace std;
using namespace Prog3::Repository;
using namespace Prog3::Core::Model;
using namespace Prog3::Core::Exception;

#ifdef RELEASE_SERVICE
string const SQLiteRepository::databaseFile = "./data/reminder-app.db";
#else
string const SQLiteRepository::databaseFile = "../data/reminder-app.db";
#endif

SQLiteRepository::SQLiteRepository() : database(nullptr) {

    string databaseDirectory = filesystem::path(databaseFile).parent_path().string();

    if (filesystem::is_directory(databaseDirectory) == false) {
        filesystem::create_directory(databaseDirectory);
    }

    int result = sqlite3_open(databaseFile.c_str(), &database);

    if (SQLITE_OK != result) {
        cout << "Cannot open database: " << sqlite3_errmsg(database) << endl;
    }
    initialize();
}

void SQLiteRepository::initialize() {
    int result = 0;
    char *errorMessage = nullptr;

    string sqlCreateTableReminderList =
        "create table if not exists reminderList("
        "id integer not null primary key autoincrement,"
        "title text not null,"
        "position integer not null UNIQUE);";

    string sqlCreateTableReminder =
        "create table if not exists reminder("
        "id integer not null primary key autoincrement,"
        "title text not null,"
        "date text not null,"
        "position integer not null,"
        "flag integer default 0," // ","
        "reminderList_id integer not null,"
        "unique (position, reminderList_id),"
        "foreign key (reminderList_id) references reminderList (id));";

    result = sqlite3_exec(database, sqlCreateTableReminderList.c_str(), NULL, 0, &errorMessage);
    handleSQLError(result, errorMessage);
    result = sqlite3_exec(database, sqlCreateTableReminder.c_str(), NULL, 0, &errorMessage);
    handleSQLError(result, errorMessage);
}

SQLiteRepository::~SQLiteRepository() {
    sqlite3_close(database);
}

App SQLiteRepository::getApp() {
    App app = App(appTitle);

    vector<ReminderList> rLists = getReminderLists();
    app.setReminderLists(rLists);

    return app;
}

std::vector<ReminderList> SQLiteRepository::getReminderLists() {
    std::vector<ReminderList> rLists;

    string sqlQueryReminderLists =
        "SELECT reminderList.id, reminderList.title, reminderList.position, reminder.id, reminder.title, reminder.position, reminder.date, reminder.flag from reminderList "
        "left join reminder on reminder.reminderList_id = reminderList.id "
        "order by reminderList.position, reminder.position";
    std::cout << sqlQueryReminderLists + "\n";
    int result = 0;
    char *errorMessage = nullptr;

    result = sqlite3_exec(database, sqlQueryReminderLists.c_str(), queryReminderListsCallback, &rLists, &errorMessage);
    handleSQLError(result, errorMessage);

    return rLists;
}

std::optional<ReminderList> SQLiteRepository::getReminderList(int id) {
    std::vector<ReminderList> rLists;

    string sqlQueryReminderLists =
        "SELECT reminderList.id, reminderList.title, reminderList.position, reminder.id, reminder.title, reminder.position, reminder.date from reminderList "
        "left join reminder on reminder.reminderList_id = reminderList.id where reminderList.id = " +
        to_string(id) +
        " order by reminderList.position, reminder.position";
    std::cout << sqlQueryReminderLists + "\n";
    int result = 0;
    char *errorMessage = nullptr;

    result = sqlite3_exec(database, sqlQueryReminderLists.c_str(), queryReminderListsCallback, &rLists, &errorMessage);
    handleSQLError(result, errorMessage);

    if (rLists.size() == 1) {
        return rLists.front(); // ???
    } else {
        return std::nullopt;
    }
}

std::optional<ReminderList> SQLiteRepository::postReminderList(std::string title, int position) {
    string sqlPostReminder =
        "INSERT INTO reminderList('title', 'position') "
        "VALUES('" +
        title + "', '" + to_string(position) + "')";
    std::cout << sqlPostReminder + "\n";
    int result = 0;
    char *errorMessage = nullptr;

    result = sqlite3_exec(database, sqlPostReminder.c_str(), NULL, 0, &errorMessage);
    handleSQLError(result, errorMessage);

    if (SQLITE_OK == result) {
        int rListId = sqlite3_last_insert_rowid(database);
        return ReminderList(rListId, title, position);
    }

    return std::nullopt;
}

std::optional<ReminderList> SQLiteRepository::putReminderList(int id, std::string title, int position) {
    string sqlUpdateReminderList =
        "UPDATE reminderList "
        "SET title = '" +
        title + "', position = '" + to_string(position) +
        "' WHERE id = " + to_string(id);
    std::cout << sqlUpdateReminderList + "\n";
    int result = 0;
    char *errorMessage = nullptr;

    result = sqlite3_exec(database, sqlUpdateReminderList.c_str(), NULL, 0, &errorMessage);
    handleSQLError(result, errorMessage);

    return getReminderList(id);
}

void SQLiteRepository::deleteReminderList(int id) {
    string sqlDeleteReminderListReminders =
        "DELETE FROM reminder "
        "WHERE reminder.reminderList_id = " +
        to_string(id);

    string sqlDeleteReminderList =
        "DELETE FROM reminderList "
        "WHERE reminderList.id = " +
        to_string(id);
    std::cout << sqlDeleteReminderListReminders + "\n";
    std::cout << sqlDeleteReminderList + "\n";

    int result = 0;
    char *errorMessage = nullptr;

    result = sqlite3_exec(database, sqlDeleteReminderListReminders.c_str(), NULL, 0, &errorMessage);
    handleSQLError(result, errorMessage);

    result = sqlite3_exec(database, sqlDeleteReminderList.c_str(), NULL, 0, &errorMessage);
    handleSQLError(result, errorMessage);
}

std::vector<Reminder> SQLiteRepository::getReminders(int reminderListId) {
    std::vector<Reminder> reminders;

    string sqlQueryReminders =
        "SELECT reminder.id, reminder.title, reminder.position, reminder.date, reminder.flag from reminder "
        "where reminder.reminderList_id = " +
        std::to_string(reminderListId) +
        " order by reminder.position";
    std::cout << sqlQueryReminders + "\n";
    int result = 0;
    char *errorMessage = nullptr;

    result = sqlite3_exec(database, sqlQueryReminders.c_str(), queryRemindersCallback, &reminders, &errorMessage);
    handleSQLError(result, errorMessage);

    return reminders;
}

std::optional<Reminder> SQLiteRepository::getReminder(int reminderListId, int reminderId) {
    std::vector<Reminder> reminders;

    string sqlQueryReminders =
        "SELECT reminder.id, reminder.title, reminder.position, reminder.date, reminder.flag from reminder "
        "where reminder.reminderList_id = " +
        std::to_string(reminderListId) + " and reminder.id = " + std::to_string(reminderId) +
        " order by reminder.position";
    std::cout << sqlQueryReminders + "\n";
    int result = 0;
    char *errorMessage = nullptr;

    result = sqlite3_exec(database, sqlQueryReminders.c_str(), queryRemindersCallback, &reminders, &errorMessage);
    handleSQLError(result, errorMessage);
    if (reminders.size() == 1) {
        return reminders.front();
    } else {
        return std::nullopt;
    }
}

std::optional<Reminder> SQLiteRepository::postReminder(int reminderListId, std::string title, int position, std::string date, int flag) {
    string sqlPostReminder =
        "INSERT INTO reminder ('title', 'date', 'position', 'flag', 'reminderList_id')"
        "VALUES ('" +
        title + "', '" + date + "', " + to_string(position) + ", " + to_string(flag) + ", " + to_string(reminderListId) + ");";
    std::cout << sqlPostReminder + "\n";
    int result = 0;
    char *errorMessage = nullptr;

    result = sqlite3_exec(database, sqlPostReminder.c_str(), NULL, 0, &errorMessage);
    handleSQLError(result, errorMessage);

    int reminderId = INVALID_ID;
    if (SQLITE_OK == result) {
        reminderId = sqlite3_last_insert_rowid(database);
    }

    return getReminder(reminderListId, reminderId);
}

std::optional<Reminder> SQLiteRepository::putReminder(int reminderListId, int reminderId, std::string title, int position, std::string date, int flag) {
    string sqlUpdateReminder =
        "UPDATE reminder SET title = '" + title + "', position = '" + to_string(position) + "', date = '" + date + "', flag = '" + to_string(flag) + // Denke die Konversion von bool zu int funktioniert, bin aber nicht 100% sicher. Muss man testen
        "' WHERE reminder.reminderList_id = " + to_string(reminderListId) + " AND reminder.id = " + to_string(reminderId);
    std::cout << sqlUpdateReminder + "\n";
    int result = 0;
    char *errorMessage = nullptr;

    result = sqlite3_exec(database, sqlUpdateReminder.c_str(), NULL, 0, &errorMessage);
    handleSQLError(result, errorMessage);

    return getReminder(reminderListId, reminderId);
}

void SQLiteRepository::deleteReminder(int reminderListId, int reminderId) {
    string sqlQueryReminder =
        "DELETE FROM reminder "
        "WHERE reminder.reminderList_id = " +
        to_string(reminderListId) +
        " AND reminder.id = " + to_string(reminderId);
    std::cout << sqlQueryReminder + "\n";
    int result = 0;
    char *errorMessage = nullptr;

    result = sqlite3_exec(database, sqlQueryReminder.c_str(), NULL, 0, &errorMessage);
    handleSQLError(result, errorMessage);
}

Reminder SQLiteRepository::getReminderFromCallback(char **fieldValues, int startIndex) {
    int index = startIndex;

    int reminderId = fieldValues[index] ? atoi(fieldValues[index]) : INVALID_ID;
    index++;

    string title = fieldValues[index] ? fieldValues[index] : "";
    index++;

    int position = fieldValues[index] ? atoi(fieldValues[index]) : 0;
    index++;

    string timestamp = fieldValues[index] ? fieldValues[index] : "";
    index++;

    int flag = fieldValues[index] ? atoi(fieldValues[index]) : 0;

    Reminder reminder(reminderId, title, position, timestamp, flag);
    return reminder;
}

ReminderList SQLiteRepository::getReminderListFromCallback(char **fieldValues, int startIndex) {
    int index = startIndex;

    int rListId = fieldValues[index] ? atoi(fieldValues[index]) : INVALID_ID;
    index++;

    string name = fieldValues[index] ? fieldValues[index] : "";
    index++;

    int position = fieldValues[index] ? atoi(fieldValues[index]) : 0;
    index++;

    ReminderList rList(rListId, name, position);
    return rList;
}

void SQLiteRepository::handleSQLError(int statementResult, char *errorMessage) {

    if (statementResult != SQLITE_OK) {
        cout << "SQL error: " << errorMessage << endl;
        sqlite3_free(errorMessage);
    }
}

int SQLiteRepository::queryReminderListsCallback(void *data, int numberOfColumns, char **fieldValues, char **columnNames) {

    std::vector<ReminderList> *prLists = static_cast<std::vector<ReminderList> *>(data);
    std::vector<ReminderList> &rLists = *prLists;

    Reminder reminder = getReminderFromCallback(fieldValues, 3);

    int reminderListId = fieldValues[0] ? atoi(fieldValues[0]) : INVALID_ID;
    bool wasReminderListAlreadyAdded = false;

    for (ReminderList &rList : rLists) {
        if (rList.getId() == reminderListId) {
            wasReminderListAlreadyAdded = true;
            if (isValid(reminder.getId())) {
                rList.addReminder(reminder);
            }
            break;
        }
    }

    if (false == wasReminderListAlreadyAdded) {
        ReminderList rList = getReminderListFromCallback(fieldValues, 0);

        if (isValid(reminder.getId())) {
            rList.addReminder(reminder);
        }

        if (isValid(rList.getId())) {
            rLists.push_back(rList);
        }
    }

    return 0;
}

int SQLiteRepository::queryRemindersCallback(void *data, int numberOfColumns, char **fieldValues, char **columnNames) {

    std::vector<Reminder> *result = static_cast<std::vector<Reminder> *>(data);

    Reminder reminder = getReminderFromCallback(fieldValues, 0);
    if (isValid(reminder.getId())) {
        result->push_back(reminder);
    }
    return 0;
}
