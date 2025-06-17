//
// Created by Lucas Watkins on 6/12/25.
//

#include "GPTApp.hpp"

// `user_env` and `pass_env` will be nullptr if not declared
GPTApp::GPTApp(const int port)  {
    assert(port >= 1 && port <= 65535);
    app.port(port);
}


void GPTApp::init_routes() {

    // Serve Static Page
    CROW_ROUTE(app, "/")([] {
        return indexHTML;
    });

    // Big "genius" idea: security through obscurity
    CROW_ROUTE(app, "/6a187bbedb71b1917f5ea38d7c960a9a/d07ff2070a2d91dbe30e044a9189525e")
    .methods("POST"_method).CROW_MIDDLEWARES(app, AuthMiddleware)
    ([](const crow::request &r) {
        // add checks later for safety
        const auto request_json = crow::json::load(r.body);

        // Race condition -> This might print before or after crow logs. Implement a crow logger to fix
        //std::cout << "Language: " << request_json["lang"] << " Message: " << request_json["msg"] << '\n';

        crow::json::wvalue response_json;

        // Echo
        response_json["lang"] = request_json["lang"];
        response_json["msg"] = request_json["msg"];

        return response_json.dump();
    });
}

void GPTApp::serve() {
    init_routes();
    app.multithreaded().run();
}

