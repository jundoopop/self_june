#include <iostream>
#include <map>
#include <set>
#include <string>

int main(void) {

  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  // Declare a map to contain the cases
  std::set<std::string> stringCases;

  // Declare a string to input
  std::string inputString = "";
  std::cin >> inputString;

  // Traverse and count
  // Length of the temp strings
  for (int i = 1; i < inputString.size() + 1; i++) {
    // Initiate the string
    std::string temp = "";
    // Set the starting point
    for (int j = 0; j < inputString.size() - i + 1; j++) {
      // Insert a string to map
      temp.append(inputString, j, i);
      // Insert a temp string to map
      stringCases.insert(temp);
      temp.clear();
    }
  }

  std::cout << stringCases.size() << "\n";
  return 0;
}