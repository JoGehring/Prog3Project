#pragma once

#include <string>

namespace Prog3 {
namespace Core {
namespace Model {

class Reminder {
  public:
    Reminder(int id, std::string givenTitle, int givenPosition, std::string givenTimestamp);
    Reminder(int id, std::string givenTitle, int givenPosition, std::string givenTimestamp, int givenFlag);
    ~Reminder(){};

    int getId() const;
    std::string getTitle() const;
    int getPos() const;
    std::string getTimestamp() const;
    int getFlag() const;

    void setID(int givenID);
    void setTitle(std::string givenTitle);
    void setPos(int givenPos);
    void setTimestamp(std::string givenTime);
    void setFlag(int flag);

  private:
    int id;
    std::string title;
    int position;
    std::string timestamp;
    int flag;
};

} // namespace Model
} // namespace Core
} // namespace Prog3
