#include <cmath> // abs()
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// A custom comparison function for the priority queue
struct Compare {
  // Compare absolute values
  bool operator()(const int &a, const int &b) {
    if (abs(a) != abs(b)) {
      return abs(a) > abs(b); // Order by absolute value
    }
    return a > b; // If absolute values are equal, order by the value itself
  }
};

int main() {
  int N;
  cin >> N;

  // Create a priority queue (min-heap) with the custom comparison
  priority_queue<int, vector<int>, Compare> heap;

  while (N--) {
    int x;
    cin >> x;

    if (x != 0) {
      // Insert the number into the heap
      heap.push(x);
    } else {
      // Remove and print the number with the smallest absolute value
      if (heap.empty()) {
        cout << 0 << '\n';
      } else {
        cout << heap.top() << '\n';
        heap.pop();
      }
    }
  }

  return 0;
}
