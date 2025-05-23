#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;

  // Initialize the adjacency matrix
  vector<vector<int>> adj(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> adj[i][j];
    }
  }

  // Floyd-Warshall algorithm
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (adj[i][k] && adj[k][j]) {
          adj[i][j] = 1;
        }
      }
    }
  }

  // Output the reachability matrix
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << adj[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}
