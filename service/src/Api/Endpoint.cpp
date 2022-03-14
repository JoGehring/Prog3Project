#include "Endpoint.hpp"

#include <iostream>

using namespace Prog3::Api;
using namespace Prog3::Core;
using namespace crow;

Endpoint::Endpoint(SimpleApp &givenApp, Manager &givenManager) : app(givenApp),
                                                                 manager(givenManager) {
    registerRoutes();
}

Endpoint::~Endpoint() {
}

void Endpoint::registerRoutes() {
    CROW_ROUTE(app, "/api/app")
    ([this](const request &req, response &res) {
        std::string jsonApp = manager.getApp();
        res.write(jsonApp);
        res.end();
    });

    CROW_ROUTE(app, "/api/app/lists")
        .methods("GET"_method, "POST"_method)([this](const request &req, response &res) {
            std::string jsonLists;

            switch (req.method) {
            case HTTPMethod::Get: {
                jsonLists = manager.getLists();
                break;
            }
            case HTTPMethod::Post: {
                jsonLists = manager.postList(req.body);
                res.code = 201;
                break;
            }
            default: {
                break;
            }
            }

            res.write(jsonLists);
            res.end();
        });

    CROW_ROUTE(app, "/api/app/lists/<int>")
        .methods("GET"_method, "PUT"_method, "DELETE"_method)([this](const request &req, response &res, int listID) {
            std::string jsonList = "{}";

            switch (req.method) {
            case HTTPMethod::Get: {
                jsonList = manager.getList(listID);
                break;
            }
            case HTTPMethod::Put: {
                jsonList = manager.putList(listID, req.body);
                break;
            }
            case HTTPMethod::Delete: {
                manager.deleteList(listID);
                break;
            }
            default: {
                break;
            }
            }

            res.write(jsonList);
            res.end();
        });

    CROW_ROUTE(app, "/api/app/lists/<int>/reminders")
        .methods("GET"_method, "POST"_method)([this](const request &req, response &res, int listID) {
            std::string jsonReminder;

            switch (req.method) {
            case HTTPMethod::Get: {
                jsonReminder = manager.getReminders(listID);
                res.code = 201;
                break;
            }
            case HTTPMethod::Post: {
                jsonReminder = manager.postReminder(listID, req.body);
                res.code = 201;
                break;
            }
            default: {
                break;
            }
            }

            res.write(jsonReminder);
            res.end();
        });

    CROW_ROUTE(app, "/api/app/lists/<int>/reminders/<int>")
        .methods("GET"_method, "PUT"_method, "DELETE"_method)([this](const request &req, response &res, int listID, int reminderID) {
            std::string jsonReminder;

            switch (req.method) {
            case HTTPMethod::Get: {
                jsonReminder = manager.getReminder(listID, reminderID); // Problem wahrscheinlich hier
                break;
            }
            case HTTPMethod::Put: {
                jsonReminder = manager.putReminder(listID, reminderID, req.body);
                res.code = 201;
                break;
            }
            case HTTPMethod::Delete: {
                manager.deleteReminder(listID, reminderID);
                break;
            }
            default: {
                break;
            }
            }

            res.write(jsonReminder);
            res.end();
        });
}
