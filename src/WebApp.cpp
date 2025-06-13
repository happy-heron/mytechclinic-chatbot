//
// Created by Lucas Watkins on 6/12/25.
//

#include "WebApp.hpp"


WebApp::WebApp(const int port) : port {port} {
    assert(port >= 1 && port <= 65535 && "Port must be in [1, 65535]");
    app.port(port);
}

void WebApp::run() {app.multithreaded().run();}
