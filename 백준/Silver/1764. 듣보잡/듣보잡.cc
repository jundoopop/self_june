#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {
  int N_dutdo, M_bodo;
  std::string name;
  std::set<std::string> dutdo_set;
  std::vector<std::string> dutdoBodo;

  std::cin >> N_dutdo >> M_bodo;

  // Add the strings
  for (int i = 0; i < N_dutdo; i++) {
    std::cin >> name;
    dutdo_set.insert(name);
  }

  // Find the names and add to the intersections
  while (M_bodo--) {
    std::cin >> name;
    if (dutdo_set.find(name) != dutdo_set.end())
      dutdoBodo.push_back(name);
  }

  // Sort the dutdoBodo vector for output by alphabetical order
  std::sort(dutdoBodo.begin(), dutdoBodo.end());

  std::cout << dutdoBodo.size() << '\n';
  for (const auto &n : dutdoBodo) {
    std::cout << n << '\n';
  }

  return 0;
}
