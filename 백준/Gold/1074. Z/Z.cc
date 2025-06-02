#include <iostream>

using namespace std;

int zed(int n, int r, int c) {
  if (n == 0) {
    return 0;
  }
  int half = 1 << (n - 1);    // equivalent to 2^(n-1)
  if (r < half && c < half) { // top-left
    return zed(n - 1, r, c);
  } else if (r < half && c >= half) { // top-right
    return half * half + zed(n - 1, r, c - half);
  } else if (r >= half && c < half) { // bottom-left
    return 2 * half * half + zed(n - 1, r - half, c);
  } else { // bottom-right
    return 3 * half * half + zed(n - 1, r - half, c - half);
  }
}

int main() {
  int N, r, c; // N: size of the square, r: row, c: column
  cin >> N >> r >> c;
  cout << zed(N, r, c) << '\n';
  return 0;
}
