//
// Created by Lucas Watkins on 6/12/25.
//

#include "GPTApp.hpp"

int main() {

    // Pointers should hopefully be valid for the duration of the program
    // Pointers will be null if variables not found
    Credentials::user = std::getenv("CHATBOT_USER");
    Credentials::pass = std::getenv("CHATBOT_PASS");

    if (!Credentials::user || !Credentials::pass || !std::getenv("OPENAI_API_KEY")
        || strchr(Credentials::user, ':') || strchr(Credentials::pass, ':')) {

        // Something is wrong, no env(s) supplied or password contains colons
        std::cerr << "YOU MUST DEFINE \"CHATBOT_USER\", \"CHATBOT_PASS\" AND \"OPENAI_API_KEY\" "
                     "ENVIRONMENT VARIABLES AND THEY MUST NOT CONTAIN COLONS!!!"
                  << std::endl;

        return 0;
    }

    // variable needed for reference and opens file
    std::ifstream file {"context.md"};

    GPTApp app {443, optional_readonly_file_t {file}};
    app.serve();

    return 0;
}