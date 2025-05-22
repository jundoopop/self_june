#include <iostream>

using namespace std;

// Function to find the year number k for a given <x:y>
int findYear(int M, int N, int x, int y) {
  // Iterate through all possible years
  for (int i = x; i <= M * N; i += M) {
    // Check if the current k satisfies both conditions
    if (i % N == y % N) {
      return i;
    }
  }
  // If no such k is found, return -1
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T; // Number of test cases

  while (T--) {
    int M, N, x, y;
    cin >> M >> N >> x >> y;

    int result = findYear(M, N, x, y);
    cout << result << '\n';
  }

  return 0;
}
