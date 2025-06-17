//
// Created by Lucas Watkins on 6/16/25.
//

#ifndef AUTHMIDDLEWARE_HPP
#define AUTHMIDDLEWARE_HPP
#include <crow_all.h>

namespace Credentials {
    inline const char *user;
    inline const char *pass;
}

struct AuthMiddleware : crow::ILocalMiddleware {

    struct context {};

    void before_handle(crow::request &request, crow::response &response, context &context) const;
    void after_handle(crow::request &request, crow::response &response, context &context) const {};
};



#endif //AUTHMIDDLEWARE_HPP
