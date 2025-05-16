#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Implement the BFS algorithm
int BFS(vector<string> &campus, int N, int M) {
  queue<pair<int, int>> q;
  vector<vector<bool>> visited(N, vector<bool>(M, false));

  // Find the starting position 'I'
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (campus[i][j] == 'I') {
        q.push({i, j});
        visited[i][j] = true;
        break;
      }
    }
  }

  int count = 0;

  // Directional vectors to move
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};

  // Perform BFS
  while (!q.empty()) {
    auto current = q.front();
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int x = current.first + dx[i];
      int y = current.second + dy[i];

      if (x >= 0 && x < N && y >= 0 && y < M && !visited[x][y] &&
          campus[x][y] != 'X') {
        if (campus[x][y] == 'P') {
          count++;
        }
        visited[x][y] = true;
        q.push({x, y});
      }
    }
  }

  return count;
}

int main() {
  int N, M;      // Row and Column
  cin >> N >> M; // Read grid dimensions

  vector<string> campus(N);
  for (int i = 0; i < N; ++i) {
    cin >> campus[i]; // Read each row of the grid
  }

  int result = BFS(campus, N, M); // Run the BFS algorithm
  if (result == 0) {
    cout << "TT" << endl; // No people found
  } else {
    cout << result << endl;
  }

  return 0;
}
