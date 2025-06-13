//
// Created by Lucas Watkins on 6/12/25.
//

#ifndef GPTAPP_HPP
#define GPTAPP_HPP

#include "index_html.hpp"
#include "WebApp.hpp"

struct GPTApp final : WebApp {
    explicit GPTApp(const int port) : WebApp{port} {}
    void init_routes() override;
};


#endif //GPTAPP_HPP
