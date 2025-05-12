#include <iostream>
#include <vector>

using namespace std;

int main() {
  /*
  2x2 -> case of 2x2 + 2x1 + 1x2
   if n is an odd, the number of case is
   dp(1) = 1
   dp(2) = 3 (1x2 + 2x1 + 2x2)
   dp(3) = 2 * 3 (1x2 + 2x1 + 2x2)
   dp(4) = dp(3) + dp(2) * 3
   dp(5) = dp(4) + dp(3) * 3
  */

  int n; // Input at the first line for the case of dp
  cin >> n;

  vector<int> dp(n + 1);
  // If n <= 3, just use initial values for output
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 3;

  // Calculate dp[i] for i >= 3
  if (n >= 3) {
    for (int i = 3; i <= n; i++) {
      dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;
    }
  }

  // Output the result
  cout << dp[n] << '\n';

  return 0;
}
