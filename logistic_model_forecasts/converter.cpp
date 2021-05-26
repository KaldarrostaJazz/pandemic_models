#include <fstream>
#include <iostream>
#include <lyra/lyra.hpp>
#include <string>
int main(int argc, const char** argv) {
  std::string file_name, output_name;
  int N;
  auto parser = lyra::opt(file_name, "file to read")["-i"]["-input"] |
                lyra::opt(output_name, "file to write")["-o"]["--output"] |
                lyra::opt(N, "number of days")["-d"]["--days"];
  auto ehiehi = parser.parse({argc, argv});
  if (!ehiehi) {
    std::cerr << ehiehi.errorMessage() << '\n';
    return 1;
  }
  std::ofstream o;
  o.open(output_name);
  if (!o) {
    std::cerr << "Select a valid path as output\n";
  }
  std::ifstream i;
  i.open(file_name);
  if (!i) {
    std::cerr << "Select a valid path as input\n";
  }
  for (int day = 1; day < N; ++day) {
    int a, b, c, d;         //, e, f;
    i >> a >> b >> c >> d;  // >> e >> f;
    o << day << " " << c << '\n';
  }
  i.close();
  o.close();
  return 0;
}
