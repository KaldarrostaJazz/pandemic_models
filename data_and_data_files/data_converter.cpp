#include <fstream>
#include <iostream>
#include <lyra/lyra.hpp>
#include <string>

int main(int argc, const char** argv) {
  std::string file_input, file_output;
  int N = 0;
  auto cli = lyra::opt(file_input, "input")["-i"]["--input"](
                 "What is the the input file?") |
             lyra::opt(file_output,
                       "output")["-o"]["--output"]("What is the output file?") |
             lyra::opt(N, "population")["-N"]["--population"](
                 "What is the total population");
  auto result = cli.parse({argc, argv});
  if (!result) {
    std::cerr << "Error in command line: " << result.errorMessage() << '\n';
    return 1;
  }
  std::ofstream output;
  output.open(file_output);
  std::ifstream input;
  input.open(file_input);
  while (input.good()) {
    int t, I, dim, dec, R, tamp;
    input >> t >> I >> dim >> dec >> R >> tamp;
    output << t << " " << N - (I + R) << " " << I << " " << R << '\n';
  }
  input.close();
  output.close();
  return 0;
}
