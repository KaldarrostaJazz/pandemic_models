#include "FitGaus.hpp"
#include <cassert>
std::vector<std::vector<double>> csv(std::istream& str) {
  std::vector<std::vector<double>> result(3);
  std::vector<double> array;
  std::vector<double> f_column;
  std::vector<double> s_column;
  std::vector<double> t_column;
  std::string line;
  int i{0};
  while (std::getline(str, line)) {
    std::stringstream line_stream(line);
    std::string cell;
    while (std::getline(line_stream, cell, ','))
      array.push_back(std::stod(cell));
    if (!line_stream && cell.empty()) array.push_back(0.);
    f_column.push_back(array[i]);
    s_column.push_back(array[i + 1]);
    t_column.push_back(array[i + 2]);
    i += 3;
  }
  result[0] = f_column;
  result[1] = s_column;
  result[2] = t_column;
  return result;
}
int main() {
  std::vector<std::vector<double>> data = csv(std::cin);
  std::vector<double> f_column = data[0];
  std::vector<double> t_column = data[2];
  assert(f_column.size() == t_column.size());
  int max = f_column.size();
  GetVal values{f_column, t_column};
  double m = values.mean();
  double s = values.stdDev();
  Gaus fitting{1, max, m, s};
  std::vector<double> new_pred = fitting.noCumulative();
  for (int i = 0; i != new_pred.size(); ++i) {
    std::cout << i + 1 << "," << values.getW() * new_pred[i] << '\n';
  }
  std::cout << "Mean: " << m << ' ' << "Std. Dev.: " << s << '\n';
}
