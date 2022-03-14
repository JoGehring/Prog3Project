#pragma once

#include "Core/Manager.hpp"
#include "crow.h"

namespace Prog3 {
namespace Api {

class Endpoint {
  public:
    Endpoint(crow::SimpleApp &givenApp, Prog3::Core::Manager &givenManager);
    ~Endpoint();

    void registerRoutes();

  private:
    crow::SimpleApp &app;
    Prog3::Core::Manager &manager;
};

} // namespace Api
} // namespace Reminder
