#include <lyra/lyra.hpp>

#include "logistic_model.hpp"

int main(int argc, const char** argv) {
  try {
    int days = 0;
    double m;
    double k;
    double alpha = 0.005;
    bool show_help = false;
    std::string file_name;
    std::array<double, 3> delta;
    delta[0] = 0.1;
    delta[1] = 0.001;
    delta[2] = 1.e-9;
    auto cli = lyra::help(show_help) | lyra::opt(days, "days")["-d"]["--days"] |
               lyra::opt(m, "m - value")["-m"]["--Mvalue"].required() |
               lyra::opt(k, "k - value")["-k"]["--Kvalue"].required() |
               lyra::opt(alpha, "alpha convergence factor")["-a"]["--alpha"] |
               lyra::opt(file_name, "file containing the data")["-f"]["--file"]
                   .required();
    auto parser = cli.parse({argc, argv});
    if (show_help) {
      std::cerr << cli;
      return 0;
    }
    if (!parser) {
      std::cerr << "Error in command line: " << parser.errorMessage() << '\n';
      return 1;
    }
    Fit pandemic_data{m, k, alpha, file_name};
    std::array<double, 3> parameters = pandemic_data.steepest_descent(delta);
    std::cout << "Estimated parameters:\n"
              << "K = " << parameters[0] << "| A = " << parameters[1]
              << "| r = " << parameters[2] << "\nEstimated infected at t = 0: "
              << parameters[0] / (parameters[1] + 1)
              << "\nThe maximum daily cases day was day "
              << log(parameters[1]) / parameters[2] << " from the data day one"
              << '\n';
    Logistic model_data{parameters};
    std::cout << "Variance = " << pandemic_data.variance(model_data) << '\n';
    if (days > 0) {
      model_data.log(days);
      std::cout << "Total cases expected"
                << " at day " << days << " from the first day of the data = "
                << model_data.cases_t(days) << '\n';
    }
    return 0;
  } catch (std::exception& error) {
    std::cerr << "Error: " << error.what();
    return 1;
  }
}
