#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> read_line(std::istream& str) {
  std::vector<std::string> result;
  std::string line;
  while (std::getline(str, line)) {
    std::stringstream line_stream(line);
    std::string cell;
    while (std::getline(line_stream, cell, ',')) result.push_back(cell);
    if (!line_stream && cell.empty()) result.push_back(" ");
  }
  return result;
}

std::vector<std::string> search_name(std::vector<std::string>& list) {
  std::vector<std::string> result;
  int size = list.size();
  int it = 0;
  for (; it != size; ++it) {
    if (list[it] == "China")
      break;
    else
      continue;
  }
  for (int i = -2; i < 3999; ++i) {
    result.push_back(list[it + i]);
  }
  return result;
}

int main() {
  std::vector<std::string> all = read_line(std::cin);
  //	std::vector<std::string> data = search_name(all);
  int day{0};
  int size = all.size();
  for (int i = 6; i < size; i += 24) {
    std::cout << day << "," << all[i] << "," << all[i + 2] << '\n';
    ++day;
  }
  return 0;
}
