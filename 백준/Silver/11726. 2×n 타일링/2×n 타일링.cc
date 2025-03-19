#include <iostream>
#include <vector>

int main() {

  // Input
  int n;
  std::cin >> n;

  // Declare a vector for the values of dp
  std::vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;

  // If n is larger than 3, use dp formula
  if (n > 3) {
    for (int i = 4; i <= n; i++) {
      dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
    }
  }

  std::cout << dp[n] << std::endl;

  return 0;
}
