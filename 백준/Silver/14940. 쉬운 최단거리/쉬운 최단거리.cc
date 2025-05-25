#include <iostream>
#include <memory.h>
#include <queue>
using namespace std;
int N, M;
int num[1001][1001] = {0};
int visited[1001][1001] = {0};
int targetx, targety;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
void bfs(int startx, int starty) {
  queue<pair<int, int>> q;
  q.push({startx, starty});
  visited[startx][starty] = 1;
  while (!q.empty()) {
    int frontx = q.front().first;
    int fronty = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = frontx + dx[i];
      int ny = fronty + dy[i];

      if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
        if (visited[nx][ny] == 0 && num[nx][ny] != 0) {
          visited[nx][ny] = visited[frontx][fronty] + 1;
          q.push({nx, ny});
        }
      }
    }
  }
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M; // Row and column of the grid

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int a;
      cin >> a;
      if (a == 2) {
        targetx = i;
        targety = j;
      }
      num[i][j] = a;
    }
  }

  bfs(targetx, targety);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (num[i][j] == 0) {
        cout << 0 << " ";
      } else {
        cout << visited[i][j] - 1 << " ";
      }
    }
    cout << "\n";
  }
}