#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  // Number of the elements
  int N;
  cin >> N;
  vector<int> arr(N);

  // Input the elements
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  // Copy the original array and save sorted values
  vector<int> sortedArr = arr;
  sort(sortedArr.begin(), sortedArr.end());

  // Remove duplicates
  sortedArr.erase(unique(sortedArr.begin(), sortedArr.end()),
                  sortedArr.end());

  // Map each element to its rank
  map<int, int> rankMap;
  for (int rank = 0; rank < sortedArr.size(); ++rank) {
    rankMap[sortedArr[rank]] = rank;
  }

  // Output of the result
  for (int i = 0; i < N; ++i) {
    cout << rankMap[arr[i]] << ' ';
  }

  // Terminate the program
  return 0;
}
