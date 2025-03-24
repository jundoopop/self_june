#include <iostream>
#include <vector>
#include <numeric>

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
    
  int N, M;
  std::cin >> N >> M;
  std::vector<int> elements(N + 1, 0);

  // Read elements into the vector and accumulate values
  for (int i = 1; i <= N; ++i)
  {
    int input_value;
    std::cin >> input_value;
    elements[i] = elements[i - 1] + input_value;
  }

  // Calculate the sum of the elements by subtracting prefix sum
  for (int iter = 0; iter < M; ++iter)
  {
    int i, j;
    std::cin >> i >> j;
    std::cout << elements[j] - elements[i - 1] << "\n";
    
  }

  return 0;
}
