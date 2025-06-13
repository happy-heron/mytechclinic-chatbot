//
// Created by Lucas Watkins on 6/12/25.
//

#include "GPTApp.hpp"

void GPTApp::init_routes() {

    // Serve Static Page
    CROW_ROUTE(app, "/")([] {
        return indexHTML;
    });
}

