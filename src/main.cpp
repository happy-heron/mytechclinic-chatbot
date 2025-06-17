//
// Created by Lucas Watkins on 6/12/25.
//

#include "GPTApp.hpp"

int main() {

    // Pointers should hopefully be valid for the duration of the program
    Credentials::user = std::getenv("CHATBOT_USER");
    Credentials::pass = std::getenv("CHATBOT_PASS");

    if (!Credentials::user || !Credentials::pass ||
        strchr(Credentials::user, ':') || strchr(Credentials::pass, ':')) {
        // Something is wrong, no env(s) supplied or password contains colons
        std::cerr << "YOU MUST DEFINE \"CHATBOT_USER\" and \"CHATBOT_PASS\" "
                     "ENVIRONMENT VARIABLES AND THEY MUST NOT CONTAIN COLONS!!!"
                  << std::endl;

        return 0;
    }

    GPTApp app {8080};
    app.serve();

    return 0;
}