#include <algorithm> // max
#include <iostream> // cin, cout
#include <vector> // vector

using namespace std;

int main() {
  // Declare the variety for the number of cases
  int iteration;
  cin >> iteration;

  vector<int> stairs(iteration);

  // Set the values of stairs
  for (auto &value : stairs) {
    cin >> value;
  }

  // When the number of stairs are same or less than 2
  if (iteration == 1) {
    cout << stairs[0] << '\n';
    return 0;
  }
  if (iteration == 2) {
    cout << stairs[0] + stairs[1] << '\n';
    return 0;
  }

  // Initialise the dp array
  vector<int> dp(iteration);

  // Allocate the dp results for counting
  dp[0] = stairs[0];
  dp[1] = stairs[0] + stairs[1]; // one step
  dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]); // two steps

  // Fill the dp array
  for (int i = 3; i < iteration; ++i) {
    dp[i] = max(dp[i - 2], dp[i - 3] + stairs[i - 1]) + stairs[i];
  }

  // Print the optimised result
  cout << dp[iteration - 1] << '\n';
  return 0;
}
