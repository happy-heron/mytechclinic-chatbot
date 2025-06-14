//
// Created by Lucas Watkins on 6/12/25.
//

#include "GPTApp.hpp"
#include <liboai.h>

int main() {

    const std::unique_ptr<WebApp> app {new GPTApp(8080)};
    WebApp::serve(app);

    return 0;
}