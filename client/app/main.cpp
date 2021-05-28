#include <getopt.h>

#include <cstdlib>
#include <iostream>
#include <string>

#include "version.h"

std::string appname;

void Usage(void) { std::cout << "Usage: " << appname << std::endl; }
void Version(void) {
    std::cout << appname << " " << PROJECT_VERSION << std::endl
              << "commit : " << COMMIT_HASH << std::endl;
}

int main(int argc, char* argv[]) {
    appname = argv[0];

    int opt;
    while ((opt = getopt(argc, argv, "hv")) != -1) {
        switch (opt) {
            case 'h':
                Usage();
                std::exit(EXIT_SUCCESS);
            case 'v':
                Version();
                std::exit(EXIT_SUCCESS);
            default: /* '?' */
                Usage();
                std::exit(EXIT_FAILURE);
        }
    }

    return 0;
}
