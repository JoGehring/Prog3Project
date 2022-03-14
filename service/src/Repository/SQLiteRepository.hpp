#pragma once

#include "Repository/RepositoryIf.hpp"
#include "sqlite3.h"
#include <optional>
#include <string>

namespace Prog3 {
namespace Repository {

class SQLiteRepository : public RepositoryIf {
  private:
    sqlite3 *database;
    void initialize();
    void handleSQLError(int statementResult, char *errorMessage);

    static bool isValid(int id) { // Not sure if necessary
        return id != INVALID_ID;
    }

    static Prog3::Core::Model::Reminder getReminderFromCallback(char **fieldValues, int startIndex);
    static Prog3::Core::Model::ReminderList getReminderListFromCallback(char **fieldValues, int startIndex);

    static int queryReminderListsCallback(void *data, int numberOfColumns, char **fieldValues, char **columnNames);
    static int queryRemindersCallback(void *data, int numberOfColumns, char **fieldValues, char **columnNames);

  public:
    SQLiteRepository();
    virtual ~SQLiteRepository();

    virtual Prog3::Core::Model::App getApp();
    virtual std::vector<Prog3::Core::Model::ReminderList> getReminderLists();
    virtual std::optional<Prog3::Core::Model::ReminderList> getReminderList(int id);
    virtual std::optional<Prog3::Core::Model::ReminderList> postReminderList(std::string title, int position);
    virtual std::optional<Prog3::Core::Model::ReminderList> putReminderList(int id, std::string title, int position);
    virtual void deleteReminderList(int id);
    virtual std::vector<Prog3::Core::Model::Reminder> getReminders(int reminderListId);
    virtual std::optional<Prog3::Core::Model::Reminder> getReminder(int reminderListId, int reminderId);
    virtual std::optional<Prog3::Core::Model::Reminder> postReminder(int reminderListId, std::string title, int position, std::string date, int flag);
    virtual std::optional<Prog3::Core::Model::Reminder> putReminder(int reminderListId, int reminderId, std::string title,  int position, std::string date, int flag);
    virtual void deleteReminder(int reminderListId, int reminderId);

    static inline std::string const appTitle = "ReminderApp";
    static inline int const INVALID_ID = -1;

    static std::string const databaseFile;
};

} // namespace Repository
} // namespace Prog3
