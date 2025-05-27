#include <iostream>
#include <queue>
#include <utility> // for pair
#include <vector>

using namespace std;

// Directions: up, down, left, right
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
  int N, M; // Row and Column
  cin >> N >> M;

  // Read the maze
  vector<vector<int>> maze(N, vector<int>(M));
  for (int i = 0; i < N; ++i) {
    string row;
    cin >> row;
    for (int j = 0; j < M; ++j) {
      maze[i][j] = row[j] - '0';
    }
  }

  // BFS setup
  queue<pair<int, int>> coordinate;
  vector<vector<int>> dist(N, vector<int>(M, 0));

  // Start from (0, 0)
  coordinate.push({0, 0});
  dist[0][0] = 1;

  // BFS
  while (!coordinate.empty()) {
    auto current = coordinate.front();
    coordinate.pop();

    int x = current.first;
    int y = current.second;

    // Check if we've reached the destination
    if (x == N - 1 && y == M - 1) {
      cout << dist[x][y] << '\n';
      return 0;
    }

    // Explore the four directions
    for (int i = 0; i < 4; ++i) {
      int nextX = x + dx[i];
      int nextY = y + dy[i];

      // Check boundaries and if the cell is a path and not visited
      if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M &&
          maze[nextX][nextY] == 1 && dist[nextX][nextY] == 0) {
        dist[nextX][nextY] = dist[x][y] + 1;
        coordinate.push({nextX, nextY});
      }
    }
  }

  // In case there's no path (though problem states there is always a path)
  cout << -1 << '\n';
  return 0;
}
