#include <iostream>
#include <string>

#include "Api/Endpoint.hpp"
#include "Api/Parser/JsonParser.hpp"
#include "Core/Manager.hpp"
#include "Repository/SQLiteRepository.hpp"
#include "crow.h"

int main() {
    crow::SimpleApp crowApplication;
    Prog3::Repository::SQLiteRepository sqliteRepository;
    Prog3::Api::Parser::JsonParser jsonParser;

    Prog3::Core::Manager manager(jsonParser, sqliteRepository);
    Prog3::Api::Endpoint endpoint(crowApplication, manager);

    crowApplication.port(8080)
        //        .multithreaded()
        .run();
}
