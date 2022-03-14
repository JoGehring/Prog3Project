#pragma once
#include "./Core/Exception/NotImplementedException.hpp"
#include "./Core/Model/App.hpp"
#include <optional>
namespace Prog3 {
namespace Repository {
class RepositoryIf {
  public:
    virtual ~RepositoryIf() {}

    virtual Prog3::Core::Model::App getApp() = 0;
    virtual std::vector<Prog3::Core::Model::ReminderList> getReminderLists() = 0;
    virtual std::optional<Prog3::Core::Model::ReminderList> getReminderList(int id) = 0;
    virtual std::optional<Prog3::Core::Model::ReminderList> postReminderList(std::string title, int position) = 0;
    virtual std::optional<Prog3::Core::Model::ReminderList> putReminderList(int id, std::string title, int position) = 0;
    virtual void deleteReminderList(int id) = 0;
    virtual std::vector<Prog3::Core::Model::Reminder> getReminders(int reminderListId) = 0;
    virtual std::optional<Prog3::Core::Model::Reminder> getReminder(int reminderListId, int reminderId) = 0;
    virtual std::optional<Prog3::Core::Model::Reminder> postReminder(int reminderListId, std::string title, int position, std::string date, int flag) = 0;
    virtual std::optional<Prog3::Core::Model::Reminder> putReminder(int reminderListId, int reminderId, std::string title, int position, std::string date, int flag) = 0;
    virtual void deleteReminder(int reminderListId, int reminderId) = 0;
};
} // namespace Repository
} // namespace Prog3
