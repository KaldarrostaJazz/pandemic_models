#include <boost/array.hpp>
#include <fstream>
#include <iostream>
#include <random>
int main() {
  double const beta = 0.7;
  double const gamma = 0.1;
  double const f = 2 * d * v * 1000 / (l * l);
  double const dt = 1 / f;
  double const time = 120;
  double const b = beta * dt;
  double const g = gamma * dt;
  int const n = 1000;
  int const num = time / dt;
  boost::array<double, num> s;
  boost::array<double, num> k;
  boost::array<double, num> r;
  k[0] = 1;
  s[0] = 999;
  r[0] = 0;
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_real_distribution<> v(0.0, 1.0);
  for (int i = 1; i < num; ++i) {
    double c = v(mt);
    if (c < (b * k[i - 1] * s[i - 1])) {
      k[i] = k[i - 1] + 1;
      s[i] = s[i - 1] - 1;
      r[i] = r[i - 1];
    } else if (c >= (1 - g * k[i - 1])) {
      r[i] = r[i - 1] + 1;
      k[i] = k[i - 1] - 1;
      s[i] = s[i - 1];
    } else {
      k[i] = k[i - 1];
      s[i] = s[i - 1];
      r[i] = r[i - 1];
    }
  }
  std::ofstream output_file;
  output_file.open("dati.dat");
  for (int q = 0; q != num; ++q) {
    std::cout << q / f << " " << s[q] << " " << k[q] << " " << r[q] << '\n';
    output_file << q / f << " " << s[q] << " " << k[q] << " " << r[q] << '\n';
  }
  output_file.close();
}
