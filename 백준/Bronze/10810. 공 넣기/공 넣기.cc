#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  // Vector to conatain numbers
  std::vector<int> ballWarehouse;

  // Iterate the numbers
  int startPoint = 0;
  int endPoint = 0;
  int numberOfBall = 0;

  // Set Input
  int baskets = 0;
  int numberToIterate = 0;
  std::cin >> baskets >> numberToIterate;

  // Set baskets
  for (int i = 0; i < baskets; i++)
    ballWarehouse.push_back(0);

  // Put the balls
  for (int i = 0; i < numberToIterate; i++) {
    std::cin >> startPoint >> endPoint >> numberOfBall;
    for (int j = startPoint - 1; j < endPoint; j++)

      ballWarehouse[j] = numberOfBall;
  }

  // Result output
  std::for_each(ballWarehouse.cbegin(), ballWarehouse.cend(),
                [](const int number) { std::cout << number << ' '; });

  return 0;
}