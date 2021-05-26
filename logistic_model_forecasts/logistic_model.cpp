#include "logistic_model.hpp"
//
// class Logistic methods definitions
//
double Logistic::cases_t(int t) {
  double cases_t = K / (1 + A * exp(-r * t));
  return cases_t;
}
double Logistic::dcases_t(int t) {
  double dcases_t = r * A * K * exp(-r * t) / pow((1 + A * exp(-r * t)), 2);
  return dcases_t;
}
std::array<double, 3> Logistic::cases_grad(int t_end) {
  std::array<double, 3> gradient;
  for (int i = 1; i <= t_end; ++i) {
    gradient[0] += 1 / (1 + A * exp(-r * i));
    gradient[1] += -K * exp(-r * i) / pow(1 + A * exp(-r * i), 2);
    gradient[2] += r * K * A * exp(-r * i) / pow(1 + A * exp(-r * i), 2);
  }
  return gradient;
}
void Logistic::log(int t_end) {
  std::ofstream output_file{"logistic_pred.dat"};
  std::ofstream output_file2{"logistic_pred_daily.dat"};
  for (int t = 1; t <= t_end; ++t) {
    output_file << t << " " << cases_t(t) << '\n';
    output_file2 << t << " " << dcases_t(t) << '\n';
  }
  output_file.close();
  output_file2.close();
}
//
// class Acquisition methods definitions
//
std::vector<int> Acquisition::Data() {
  std::vector<int> Data;
  std::ifstream data_file{file_name};
  if (!data_file) std::cerr << "Select a valid path";
  while (data_file.good()) {
    int t, cases;
    data_file >> t >> cases;
    Data.push_back(cases);
  }
  return Data;
}
std::vector<int> Acquisition::dData() {
  std::vector<int> dData;
  std::ifstream data_file{file_name};
  if (!data_file) std::cerr << "Select a valid path";
  while (data_file.good()) {
    int t, cases;
    data_file >> t >> cases;
    dData.push_back(cases);
  }
  for (long unsigned int i = 1; i != dData.size(); ++i)
    dData[i] += -dData[i - 1];
  return dData;
}
//
// class Fit variables and methods definitions
//
std::array<double, 3> Fit::initial_guess() {
  std::array<double, 3> parameters;
  int x = pandemy.Data()[k - 2 * m - 1];
  int y = pandemy.Data()[k - m - 1];
  int z = pandemy.Data()[k - 1];
  long long int k_up = ( x * y - 2 * x * z + y * z);
  long long int den = y * y - x * z;
  long long int A_up = (z - y) * (y - x); 
  long int base1 = z * (y - x);
  long int base2 =  x * (z - y);
  long double base = base1/base2;
  long double exponent = (k - m) / m;
  long double power = pow(base, exponent);
  // K_0
  parameters[0] = y * k_up / den;
  // A_0
  parameters[1] = (A_up / den) * power;
  // r_0
  parameters[2] = log(base) / m;
  if (parameters[0] <= 0. || parameters[1] <= 0. || parameters[2] <= 0. ||
      parameters[0] < z) {
    throw std::range_error(
        "It wasn't possible to find an initial guess for K_0, A_0, r_0\n");
  }
  else {
    std::cout << "An initial guess was found:\n"
              << "K_0 = " << parameters[0] << " A_0 = " << parameters[1]
              << " r_0 = " << parameters[2] << " " << exponent << '\n';
  }
  return parameters;
}
double Fit::std_dev(Logistic& theoretical_pandemy) {
  int n = pandemy.Data().size();
  double variance = 0.;
  for (int i = 0; i != n; ++i)
    variance += pandemy.Data()[i] - theoretical_pandemy.cases_t(i + 1);
  return variance / n;
}
std::array<double, 3> Fit::var_grad(Logistic& theoretical_pandemy) {
  std::array<double, 3> gradient;
  gradient[0] = -2 * std_dev(theoretical_pandemy) *
                theoretical_pandemy.cases_grad(pandemy.Data().size())[0];
  gradient[1] = -2 * std_dev(theoretical_pandemy) *
                theoretical_pandemy.cases_grad(pandemy.Data().size())[1];
  gradient[2] = -2 * std_dev(theoretical_pandemy) *
                theoretical_pandemy.cases_grad(pandemy.Data().size())[2];
  return gradient;
}
std::array<double, 3> Fit::steepest_descent(
    std::array<double, 3> const& delta) {
  std::array<double, 3> p = initial_guess();
  for (int iteration = 1; iteration != max_number_of_iterations; ++iteration) {
    Logistic lattice_curve{p};
    p[0] += -alpha * var_grad(lattice_curve)[0] * delta[0];
    p[1] += -alpha * var_grad(lattice_curve)[1] * delta[1];
    p[2] += -alpha * var_grad(lattice_curve)[2] * delta[2];
  }
  return p;
}
