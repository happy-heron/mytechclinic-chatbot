//
// Created by Lucas Watkins on 6/12/25.
//

#include "GPTApp.hpp"

void GPTApp::init_routes() {

    // Serve Static Page
    CROW_ROUTE(app, "/")([] {
        return indexHTML;
    });

    // Big "genius" idea: security through obscurity
    CROW_ROUTE(app, "/6a187bbedb71b1917f5ea38d7c960a9a/d07ff2070a2d91dbe30e044a9189525e").methods("POST"_method)
    ([](const crow::request &r) {
        const auto request_json = crow::json::load(r.body);

        std::cout << "Language: " << request_json["lang"] << " Message: " << request_json["msg"] << '\n';

        crow::json::wvalue response_json;

        // Echo
        response_json["lang"] = request_json["lang"];
        response_json["msg"] = request_json["msg"];

        return response_json.dump();
    });
}

