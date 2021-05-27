#include <iostream>
#include <string>

std::string appname;

void Usage(void) { std::cout << "Usage: " << appname << std::endl; }

int main(int argc, char* argv[]) {
    appname = argv[0];
    return 0;
}
