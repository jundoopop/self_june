#include <iostream>
#include <vector>

int main() {

  // Declare a vector for the values of dp
  // dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 3
  std::vector<int> dp = {0, 1, 2, 3};

  // input
  int n;
  std::cin >> n;

  // if (n < 1 || n > 1000) {
  //   std::cerr << "Input out of range\n";
  //   return 1;
  // }

  // If n is larger than 3, use dp formula
  // dp[n] = dp[n-2] * 2 + dp[n-1]
  if (n > 3) {
    for (int i = 4; i < n + 1; i++) {
      dp.push_back((dp[i - 2] + dp[i - 1]) % 10007);
    }
  }

  std::cout << dp[n] << std::endl;

  return 0;
}