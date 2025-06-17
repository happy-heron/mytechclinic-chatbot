//
// Created by Lucas Watkins on 6/12/25.
//

#ifndef GPTAPP_HPP
#define GPTAPP_HPP

#include "index_html.hpp"
#include <crow_all.h>
#include <cassert>
#include "AuthMiddleware.hpp"

class GPTApp {

    crow::App<AuthMiddleware> app;
    void init_routes();

    public:
    explicit GPTApp(int /*port*/);
    void serve();
};


#endif //GPTAPP_HPP
