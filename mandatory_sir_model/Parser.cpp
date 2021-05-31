#include "Parser.hpp"

Command::Command(lyra::cli& cli) {
  cli.add_argument(
      lyra::command(
          "sir", [this](lyra::group const& group) { this->sir_command(group); })
          .help("Run the sir simulation mode")
          .add_argument(lyra::help(show_help))
          .add_argument(lyra::opt(beta, "beta")
                            .name("-b")
                            .name("--beta")
			    .required()
                            .help("Set the beta value"))
          .add_argument(lyra::opt(gamma, "gamma")
                            .name("-g")
                            .name("--gamma")
			    .required()
                            .help("Set the gamma value"))
          .add_argument(lyra::opt(S, "susceptibles")
                            .name("-S")
                            .name("--susceptibles")
			    .required()
                            .help("Set the number of susceptibles at the start "
                                  "of the pandemic"))
          .add_argument(lyra::opt(I, "infected")
                            .name("-I")
                            .name("--infected")
			    .required()
                            .help("Set the number of infected at the start of "
                                  "the pandemic"))
          .add_argument(
              lyra::opt(R, "removed")
                  .name("-R")
                  .name("--removed")
		  .required()
                  .help(
                      "Set the number of removed at the start of the pandemic"))
          .add_argument(
              lyra::opt(duration, "duration")
                  .name("-d")
                  .name("--duration")
		  .choices([](int value) {return value > 0;})
		  .required()
                  .help("Set the duration (days) of the simulation")));
  cli.add_argument(
      lyra::command(
          "fit", [this](lyra::group const& group) { this->fit_command(group); })
          .help("Run the fitting mode")
          .add_argument(lyra::help(show_help))
          .add_argument(lyra::opt(precision, "precision")
                            .name("-p")
                            .name("--precision")
                            .choices(0.1, 0.01, 0.001)
                            .help("Set the decimal precision of the estimate "
                                  "of the parameters"))
          .add_argument(
              lyra::opt(file_name, "data file")
                  .name("-f")
                  .name("--file")
		  .required()
                  .help("Select the file containing the data to fit")));
}
void Command::sir_command(lyra::group const& group) {
  if (show_help)
    std::cerr << group;
  else {
    std::cout << "RUNNING SIR SIMULATION MODE\n";
    State initial_state{S, I, R};
    Virus virus{beta, gamma};
    Pandemy pandemy{initial_state, virus};
    auto const states = pandemy.progression(duration);
    // print(states);
    print_simple(states);
  }
}
void Command::fit_command(const lyra::group& group) {
  if (show_help)
    std::cerr << group;
  else {
    std::cout << "RUNNING THE FITTING MODE\n";
    Pandemy pandemy;
    auto const pandemic_data = pandemy.get_data(file_name);
    auto const virus = get_parameters(pandemic_data, precision);
    std::cout << "Estimated parameters:\n"
              << virus.beta << " " << virus.gamma << '\n';
  }
}
