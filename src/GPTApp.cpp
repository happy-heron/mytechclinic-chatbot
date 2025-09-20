//
// Created by Lucas Watkins on 6/12/25.
//

#include "GPTApp.hpp"

using namespace std::string_literals;

/*
 * Creates a GPT App. Port must be in [1, 65535]. Context file is optional
 */
GPTApp::GPTApp(const int port, const optional_readonly_file_t file) {

    assert(port >= 1 && port <= 65535);
    app.port(port);

    if (!oai_api.auth.SetKeyEnv("OPENAI_API_KEY")) {
        std::cout << "INVALID OPENAI API KEY!!!\n";
        std::exit(0);
    }

    if (!conv.AddUserData("You are a virtual assistant for MyTechClinic. "
                          "You primarily help the elderly so please be gentle. "
                          "Please treat each message to you as a separate incident unless obvious it isn't")) {

        std::cerr << "FAILED TO INITALIZE BASE PROMPT\n";
    }

    if (file && file->get().is_open()) {

        context += "Frequently asked questions from the clinic:\n";

        // copy to string
        for (std::string line; std::getline(file->get(), line);) {
            context += line + '\n';
        }

        file->get().close();

        if (!conv.AddUserData(context)) {
            std::cerr << "FAILED TO ADD CONTEXT\n";
        }

    } else {
        std::cerr << "WARNING: CONTEXT FILE MISSING OR INACCESSIBLE\n" << std::endl;
    }
}


void GPTApp::init_routes() {

    /*
     * Serves static landing page
     */
    CROW_ROUTE(app, "/")([] {
        return indexHTML;
    });


    //TODO: Prevent Data Races Between threads on this method

    /*
     * API Endpoint for chat completions with the model.
     * Big "genius" idea: security through obscurity (with the URL).
     */
    CROW_ROUTE(app, "/6a187bbedb71b1917f5ea38d7c960a9a/d07ff2070a2d91dbe30e044a9189525e")
    .methods("POST"_method).CROW_MIDDLEWARES(app, AuthMiddleware)
    ([this](const crow::request &r) {
        //TODO: add checks later for safety
        const auto request_json = crow::json::load(r.body);

        // Race condition -> This might print before or after crow logs. Implement a crow logger to fix
        //std::cout << "Language: " << request_json["lang"] << " Message: " << request_json["msg"] << '\n';

        crow::json::wvalue response_json;


        if (!conv.AddUserData(static_cast<std::string>(request_json["msg"]))) {
            std::cerr << "FAILED TO UPDATE CONVERSATION\n";
        }

        const liboai::Response chat_resp { oai_api.ChatCompletion->create("gpt-3.5-turbo", conv) };

        if (!conv.Update(chat_resp)) {
            std::cerr << "FAILED TO UPDATE CONVERSATION AFTER RESPONSE\n";
        } else {
            // Echo
            response_json["lang"] = request_json["lang"];
            response_json["msg"] = conv.GetLastResponse();

            return response_json.dump();
        }
        return R"({"lang": "null", "msg": "null"})"s;
    });
}

/*
 * Initializes all routes and starts the webserver using Crow's API.
 */
void GPTApp::serve() {
    init_routes();
    app.multithreaded().run();
}

