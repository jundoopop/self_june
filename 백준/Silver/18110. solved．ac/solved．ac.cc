#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

int main(void) {

  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  // Declare a variable "opinion".
  // This is a number suggested by each users
  int opinion = 0;

  // Declare a variable named "numberOfRates"
  // This is a number to iterate
  int numberOfRates = 0;
  std::cin >> numberOfRates;

  // numberOfRates would be same or larger than 1 by numberOfRates is set by 4
  if (numberOfRates > 0) {
    // Declare an integer named "upDownCut"
    // This is a number to cut highest and lowest 15% of the rates
    int upDownCut = 0;
    upDownCut = int(round(numberOfRates * 0.15));

    // Declare a vector named "listOfRates"
    // It contains each rate users suggested
    std::vector<int> listOfRates;

    for (int i = 0; i < numberOfRates; i++) {
      // Set a score and push to the vector
      std::cin >> opinion;
      listOfRates.push_back(opinion);
    }

    // Sort a vector by ascending order
    std::sort(listOfRates.begin(), listOfRates.end());

    // Compute a sum of list and get a mean
    double sumOfRates =
        std::accumulate(std::next(listOfRates.begin(), upDownCut),
                        std::next(listOfRates.end(), -upDownCut), 0);

    double average = round(sumOfRates / (numberOfRates - upDownCut * 2));
    int result = int(average);

    // Print a result
    std::cout << result << "\n";
  } else
    std::cout << "0\n";

  return 0;
}