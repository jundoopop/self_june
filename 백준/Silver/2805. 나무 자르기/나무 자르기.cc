#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

long long calculateWood(const vector<int> &trees, int height) {
  long long totalWood = 0;
  for (int tree : trees) {
    if (tree > height) {
      totalWood += tree - height;
    }
  }
  return totalWood;
}

int findMaxHeight(const vector<int> &trees, int requiredWood) {
  int low = 0;
  int high = *max_element(trees.begin(), trees.end());
  int result = 0;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    long long wood = calculateWood(trees, mid);

    if (wood >= requiredWood) {
      result = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return result;
}

int main() {
  int N, M;
  cin >> N >> M;

  // Using a smart pointer to manage the array
  unique_ptr<int[]> trees(new int[N]);
  for (int i = 0; i < N; ++i) {
    cin >> trees[i];
  }

  // Convert the unique_ptr to a vector for easier manipulation
  vector<int> treesVector(trees.get(), trees.get() + N);

  int maxHeight = findMaxHeight(treesVector, M);
  cout << maxHeight << endl;

  return 0;
}
