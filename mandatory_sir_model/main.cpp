#include <iostream>
#include <lyra/lyra.hpp>

#include "Parser.hpp"

int main(int argc, const char** argv) {
  try {
    bool show_help = false;
    auto cli = lyra::cli();
    cli.add_argument(lyra::help(show_help));
    Command option{cli};
    auto parser = cli.parse({argc, argv});
    if (show_help) {
      std::cerr << cli << '\n';
      return 0;
    }
    if (!parser) {
      std::cerr << parser.errorMessage() << '\n';
      return 1;
    }
    return 0;
  } catch (std::exception& error) {
    std::cerr << "Error: " << error.what();
    return 1;
  }
}
