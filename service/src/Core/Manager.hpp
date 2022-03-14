#pragma once

#include "Api/Parser/ParserIf.hpp"
#include "Repository/RepositoryIf.hpp"

namespace Prog3 {
namespace Core {
class Manager {
  private:
    Prog3::Repository::RepositoryIf &repository;
    Prog3::Api::Parser::ParserIf &parser;

  public:
    Manager(Prog3::Api::Parser::ParserIf &givenParser, Prog3::Repository::RepositoryIf &givenRepository);
    ~Manager();

    std::string getApp();
    std::string getLists();
    std::string getList(int listId);
    std::string postList(std::string request);
    std::string putList(int listId, std::string request);
    void deleteList(int listId);

    std::string getReminders(int listId);
    std::string getReminder(int listId, int reminderId);
    std::string postReminder(int listId, std::string request);
    std::string putReminder(int listId, int reminderId, std::string request);
    void deleteReminder(int listId, int reminderId);
};

} // namespace Core
} // namespace Prog3
