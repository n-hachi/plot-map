#include <getopt.h>

#include <cstdlib>
#include <iostream>
#include <string>

std::string appname;

void Usage(void) { std::cout << "Usage: " << appname << std::endl; }

int main(int argc, char* argv[]) {
    appname = argv[0];

    int opt;
    while ((opt = getopt(argc, argv, "h")) != -1) {
        switch (opt) {
            case 'h':
                Usage();
                std::exit(EXIT_SUCCESS);
            default: /* '?' */
                Usage();
                std::exit(EXIT_FAILURE);
        }
    }

    return 0;
}
