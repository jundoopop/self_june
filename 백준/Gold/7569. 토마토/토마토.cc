#include <algorithm> // For max
#include <array>     // For array
#include <iostream>  // For cin, cout, ios_base, '\n'
#include <queue>     // For queue
#include <tuple>     // For tuple, make_tuple, and structured bindings
#include <vector>    // For vector

using namespace std;

// Define a structure for directions to make the code cleaner
// dx: change in M (width), dy: change in N (length/depth), dz: change in H
// (height)
struct Direction {
  int dx;
  int dy;
  int dz;
};

// Use a static constexpr std::array for directions
// Order of changes in Direction struct: M, N, H
static constexpr array<Direction, 6> directions = {{
    {1, 0, 0},
    {-1, 0, 0}, // Change in M (width)
    {0, 1, 0},
    {0, -1, 0}, // Change in N (length/depth)
    {0, 0, 1},
    {0, 0, -1} // Change in H (height)
}};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int M, N, H; // M: width (x-like), N: length (y-like), H: height (z-like)
  cin >> M >> N >> H;

  // box[h_idx][n_idx][m_idx]
  vector<vector<vector<int>>> box(H, vector<vector<int>>(N, vector<int>(M)));
  queue<tuple<int, int, int>> q; // Stores (h_idx, n_idx, m_idx)

  bool has_unripe_tomatoes = false;
  // Read the input and enqueue the initial ripe tomatoes
  for (int h_idx = 0; h_idx < H; ++h_idx) {
    for (int n_idx = 0; n_idx < N; ++n_idx) {
      for (int m_idx = 0; m_idx < M; ++m_idx) {
        cin >> box[h_idx][n_idx][m_idx];
        if (box[h_idx][n_idx][m_idx] == 1) {
          q.push(make_tuple(h_idx, n_idx, m_idx));
        } else if (box[h_idx][n_idx][m_idx] == 0) {
          has_unripe_tomatoes = true;
        }
      }
    }
  }

  // If there are no unripe tomatoes to begin with, 0 days.
  if (!has_unripe_tomatoes) {
    cout << 0 << '\n';
    return 0;
  }
  // If there are unripe tomatoes but no starting ripe ones, they can't ripen.
  if (q.empty()) { // This implies has_unripe_tomatoes is true due to the check
                   // above
    cout << -1 << '\n';
    return 0;
  }

  // BFS to simulate ripening
  while (!q.empty()) {
    auto [currentH, currentN, currentM] = q.front();
    q.pop();

    for (const auto &dir : directions) {
      int nextH = currentH + dir.dz; // dz corresponds to H dimension
      int nextN = currentN + dir.dy; // dy corresponds to N dimension
      int nextM = currentM + dir.dx; // dx corresponds to M dimension

      if (nextH >= 0 && nextH < H && nextN >= 0 && nextN < N && nextM >= 0 &&
          nextM < M) {
        if (box[nextH][nextN][nextM] == 0) { // If unripe
          box[nextH][nextN][nextM] = box[currentH][currentN][currentM] + 1;
          q.push(make_tuple(nextH, nextN, nextM));
        }
      }
    }
  }

  int max_days = 0;
  // Check if all tomatoes ripened and find the maximum day
  for (int h_idx = 0; h_idx < H; ++h_idx) {
    for (int n_idx = 0; n_idx < N; ++n_idx) {
      for (int m_idx = 0; m_idx < M; ++m_idx) {
        if (box[h_idx][n_idx][m_idx] == 0) {
          // If any tomato is still unripe
          cout << -1 << '\n';
          return 0;
        }
        max_days = max(max_days, box[h_idx][n_idx][m_idx]);
      }
    }
  }

  // The days stored are 1-indexed (day 1 means initial state).
  // So, the number of days passed is max_days - 1.
  cout << max_days - 1 << '\n';

  return 0;
}
