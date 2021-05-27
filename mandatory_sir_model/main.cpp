#include <iostream>
#include <lyra/lyra.hpp>

#include "Least_Squares.hpp"
#include "Pandemy.hpp"
#include "Print.hpp"

int main(int argc, const char** argv) {
  std::string option;
  bool show_help = false;
  auto cli = lyra::cli();
  cli.add_argument(lyra::help(show_help));
  cli.add_argument(lyra::opt(option, "running_option")
                       .name("-o")
                       .name("--opt")
                       .help("Choose if fit_mode or sir_mode"));
  auto pippo_inzaghi = cli.parse({argc, argv});
  if (show_help) {
    std::cerr << cli << '\n';
    return 0;
  }
  if (option == "sir") {
    double beta, gamma, S, I, R;
    int duration;
    cli.add_argument(lyra::help(show_help));
    cli.add_argument(lyra::opt(beta, "beta")
                         .name("-b")
                         .name("--beta")
                         .help("Set the beta value"));
    cli.add_argument(lyra::opt(gamma, "gamma")
                         .name("-g")
                         .name("--gamma")
                         .help("Set the gamma value"));
    cli.add_argument(
        lyra::opt(S, "susceptibles")
            .name("-S")
            .name("--susceptibles")
            .help(
                "Set the number of susceptibles at the start of the pandemic"));
    cli.add_argument(
        lyra::opt(I, "infected")
            .name("-I")
            .name("--infected")
            .help("Set the number of infected at the start of the pandemic"));
    cli.add_argument(
        lyra::opt(R, "removed")
            .name("-R")
            .name("--removed")
            .help("Set the number of removed at the start of the pandemic"));
    cli.add_argument(lyra::opt(duration, "duration")
                         .name("-d")
                         .name("--duration")
                         .help("Set the duration of the simulation"));
    auto pippo_franco = cli.parse({argc, argv});
    if (!pippo_franco) {
      std::cerr << "Error in command line: " << pippo_franco.errorMessage()
                << '\n';
      std::cerr << cli << '\n';
      return 1;
    }
    State initial_state{S, I, R};
    Virus virus{beta, gamma};
    Pandemy pandemy{initial_state, virus};
    auto const states = pandemy.progression(duration);
    // print(states);
    print_simple(states);
    return 0;
  } else if (option == "fit") {
    std::string data_file;
    double precision = 0.01;
    cli.add_argument(lyra::help(show_help));
    cli.add_argument(lyra::opt(data_file, "data_file")
                         .name("-f")
                         .name("--file")
                         .required()
                         .help("Select the file containing the data to fit"));
    cli.add_argument(
        lyra::opt(precision, "fit precision")
            .name("-p")
            .name("--precision")
            .choices(0.1, 0.01, 0.001)
            .help("Set the decimal precision of the estimated paramteres"));
    auto pippo_baudo = cli.parse({argc, argv});
    if (!pippo_baudo) {
      std::cerr << "Error in command line: " << pippo_baudo.errorMessage()
                << '\n';
      std::cerr << cli << '\n';
      return 1;
    }
    Pandemy pandemy;
    auto const pandemic_data = pandemy.get_data(data_file);
    auto const virus = get_parameters(pandemic_data, precision);
    // print_fitting(pandemic_data,
    std::cout << "Estimated parameters:\n"
              << virus.beta << " " << virus.gamma << '\n';
    return 0;
  } else {
    std::cerr << "Please, insert a valid option, either fit or sir\n";
    std::cerr << cli << '\n';
    return 0;
  }
}
