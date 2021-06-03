#include <fstream>
#include <iostream>
#include <lyra/lyra.hpp>
#include <stdexcept>
#include <string>
int main(int argc, const char** argv) {
  try {
    std::string file_name;
    std::string output_name;
    int N = 0;
    bool show_help = false;
    auto cli =
        lyra::help(show_help) |
        lyra::opt(file_name, "file to read")["-i"]["--input"].required() |
        lyra::opt(output_name, "file to write")["-o"]["--output"].required() |
        lyra::opt(N, "number of days")["-d"]["--days"].choices(
            [](int value) { return value >= 0; });
    auto parser = cli.parse({argc, argv});
    if (show_help) {
      std::cerr << cli;
      return 0;
    }
    if (!parser) {
      std::cerr << parser.errorMessage() << '\n';
      return 1;
    }
    std::ofstream output{output_name};
    if (!output) throw std::runtime_error("Select a valid path as output\n");
    std::ifstream input{file_name};
    if (!input) throw std::runtime_error("Select a valid path as input\n");
    if (N != 0) {
      for (int day = 1; day != N; ++day) {
        // predisposed for |day|S|I|R| format
        int time;
        int value_1;
        int value_2;  // infected
        int value_3;
        // int value_4;
        // excetera...
        input >> time >> value_1 >> value_2 >> value_3;  // >> value_4 ...
        output << day << " " << value_2 << '\n';
      }
    } else {
      while (input.good()) {
        // predisposed for |day|S|I|R| format
        int day = 1;
        int time;
        int value_1;
        int value_2;  // infected
        int value_3;
        // int value_4;
        // excetera...
        input >> time >> value_1 >> value_2 >> value_3;  // >> value_4 ...
        output << day << " " << value_2 << '\n';
        ++day;
      }
    }
    input.close();
    output.close();
    return 0;
  } catch (std::exception& error) {
    std::cerr << "Error: " << error.what() << '\n';
    return 1;
  }
}
