#include <CLI/CLI.hpp>
#include <iostream>


int main(int argc, char* argv[]) {
    CLI::App app{ "Hello from CLI" };
    bool someFlag = false;
    app.add_option("-f", someFlag, "some useless flag");
    std::cout << "Some flag is " << someFlag << std::endl;
    CLI11_PARSE(app, argc, argv);
}