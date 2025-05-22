#include <iostream>
#include <string>

using namespace std;

int main() {
  int N; // The number of O
  cin >> N;

  string P = ""; // Making P_n 
  for (int i = 0; i < 2 * N + 1; i++) {
    if (i % 2 == 0) {
      P.push_back('I');
    } else {
      P.push_back('O');
    }
  }

  int M;
  cin >> M;

  string S;
  cin >> S;

  int result = 0;

  // Compare the string S with the pattern P
  for (int i = N; i <= M - N - 1; i++) {
    if (S.substr(i - N, 2 * N + 1) == P) {
      result += 1;
    }
  }

  cout << result << '\n';

  return 0;
}
