//
// Created by Lucas Watkins on 6/16/25.
//

#include "AuthMiddleware.hpp"

void fail_auth(crow::response &response) {
    response.code = 401;
    response.add_header("WWW-Authenticate", "Basic");
    response.end();
}

void AuthMiddleware::before_handle(crow::request &request, crow::response &response, context &context) const {

    // check if header exists
    if (!request.headers.contains("Authorization")) {
        fail_auth(response);
        return;
    }

    const std::string &header {request.get_header_value("Authorization")};

    if (header.size() < 6) {
        fail_auth(response);
        return;
    }

    const std::string creds {
        crow::utility::base64decode (
            header.substr(6)
        )
    };

    const size_t colon_idx {creds.find(':')};

    const std::string user {creds.substr(0, colon_idx)};
    const std::string pass {creds.substr(colon_idx + 1)};

    if (strcmp(Credentials::user, user.c_str()) != 0 || strcmp(Credentials::pass, pass.c_str()) != 0) {
        fail_auth(response);
    }
}
