#include <iostream>
#include <vector>

using namespace std;

// Function to check if the grid is correctly coloured as a square
bool isSquared(const vector<vector<int>> &grid, int x, int y, int size) {
  int color = grid[x][y];
  for (int i = x; i < x + size; ++i) {
    for (int j = y; j < y + size; ++j) {
      if (grid[i][j] != color) {
        return false;
      }
    }
  }
  return true;
}

// Function to count the number of blue and white squares
void countSquares(const vector<vector<int>> &grid, int x, int y, int size,
                  int &blue, int &white) {
  if (isSquared(grid, x, y, size)) {
    if (grid[x][y] == 1) {
      blue++;
    } else {
      white++;
    }
    return;
  }

  int newSize = size / 2;

  // Recursively count the number of blue and white squares
  countSquares(grid, x, y, newSize, blue, white);
  countSquares(grid, x, y + newSize, newSize, blue, white);
  countSquares(grid, x + newSize, y, newSize, blue, white);
  countSquares(grid, x + newSize, y + newSize, newSize, blue, white);
}

int main() {
  // Number of column and row
  int N;
  cin >> N;

  vector<vector<int>> grid(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> grid[i][j];
    }
  }

  int blue = 0, white = 0;
  countSquares(grid, 0, 0, N, blue, white);

  cout << white << '\n';
  cout << blue << '\n';

  return 0;
}
