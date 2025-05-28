#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 1, 0, 0}; // Directions for moving in the grid
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y, vector<vector<int>> &square,
         vector<vector<bool>> &visited, int &cnt) {
  int n = square.size();
  visited[x][y] = true;
  cnt++;

  for (int i = 0; i < 4; i++) {
    // Get the next coordinates
    int nx = x + dx[i];
    int ny = y + dy[i];

    // Check if the next coordinates are within bounds
    if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
      if (square[nx][ny] == 1 && !visited[nx][ny]) {
        dfs(nx, ny, square, visited, cnt);
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  // Initialise the square
  vector<vector<int>> square(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < n; j++) {
      square[i][j] = row[j] - '0';
    }
  }

  // Initialise the visited array
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  vector<int> complexCounts;

  // Perform DFS to find the number of complexes
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (square[i][j] == 1 && !visited[i][j]) {
        int cnt = 0;
        dfs(i, j, square, visited, cnt);
        complexCounts.push_back(cnt);
      }
    }
  }

  // Sort the complex counts
  sort(complexCounts.begin(), complexCounts.end());

  // Print the number of complexes
  cout << complexCounts.size() << '\n';
  for (int cnt : complexCounts) {
    cout << cnt << '\n';
  }

  return 0;
}
