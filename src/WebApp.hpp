//
// Created by Lucas Watkins on 6/12/25.
//

#ifndef WEBAPP_HPP
#define WEBAPP_HPP
#include "../include/crow_all.h"
#include <cassert>
#include <iostream>

class WebApp {

    void run();

    protected:
    crow::SimpleApp app;
    int port;
    virtual void init_routes() = 0;

    public:
    virtual ~WebApp() = default;

    explicit WebApp(int /*port*/);

    static void serve(const std::unique_ptr<WebApp> &web_app) {
        if (web_app) {
            web_app->init_routes();
            web_app->run();
        } else {
            std::cerr << "WebApp could not be created. (NPE)" << std::endl;
        }
    }
};



#endif //WEBAPP_HPP
