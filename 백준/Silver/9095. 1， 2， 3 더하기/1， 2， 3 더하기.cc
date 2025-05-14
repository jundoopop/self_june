#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Initialize the dp vector with base cases
  vector<int> dp = {0, 1, 2, 4};

  int iteration;
  cin >> iteration; // Read the number of test cases

  while (iteration--) {
    int n;
    cin >> n;

    // Validate input
    if (n <= 0 || n > 10) {
      cerr << "Please enter a positive integer between 1 and 10." << endl;
      return 1;
    }

    // If n is less than 4, print the pre-defined value
    if (n < 4) {
      cout << dp[n] << endl;
    } else {
      // If dp size is less than or equal to n, compute the number of ways
      if (dp.size() <= n) {
        // Extend the dp vector using push_back
        for (int i = dp.size(); i <= n; ++i) {
          dp.push_back(dp[i - 1] + dp[i - 2] +
                       dp[i - 3]); // Compute the number of ways
        }
      }
      cout << dp[n] << endl;
    }
  }

  return 0;
}
