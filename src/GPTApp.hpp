//
// Created by Lucas Watkins on 6/12/25.
//

#ifndef GPTAPP_HPP
#define GPTAPP_HPP

#include "index_html.hpp"
#include <crow_all.h>
#include <cassert>
#include "AuthMiddleware.hpp"
#include <filesystem>

using optional_readonly_file_t = std::optional<std::reference_wrapper<std::ifstream>>;

class GPTApp {

    crow::App<AuthMiddleware> app;
    std::string context;

    void init_routes();


    public:
    explicit GPTApp(int /*port*/, optional_readonly_file_t /*file*/ = std::nullopt);
    void serve();
};


#endif //GPTAPP_HPP
