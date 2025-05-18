#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void dfs(int start, vector<vector<int>> &graph, vector<bool> &visited) {
  cout << start << " ";
  visited[start] = true;

  for (int neighbor : graph[start]) {
    if (!visited[neighbor]) {
      dfs(neighbor, graph, visited);
    }
  }
}

void bfs(int start, vector<vector<int>> &graph, vector<bool> &visited) {
  queue<int> q;
  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int current = q.front();
    q.pop();
    cout << current << " ";

    for (int neighbor : graph[current]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
}

int main() {
  int N, M, V;
  cin >> N >> M >> V;

  vector<vector<int>> graph(N + 1);
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  // Sort the adjacency list for each node to ensure lexicographical order
  for (int i = 1; i <= N; ++i) {
    sort(graph[i].begin(), graph[i].end());
  }

  vector<bool> visited(N + 1, false);
  dfs(V, graph, visited);
  cout << '\n';

  fill(visited.begin(), visited.end(), false);
  bfs(V, graph, visited);
  cout << '\n';

  return 0;
}
