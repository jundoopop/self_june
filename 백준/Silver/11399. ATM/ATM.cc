#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric> // For std::accumulate
#include <ranges>  // For std::ranges

int main()
{
  int N; // N is the number of customers
  std::cin >> N;

  std::vector<int> tasks(N);
  // This loop saves each customers' minutes for work
  for (auto &minute : tasks)
  {
    std::cin >> minute;
  }

  std::ranges::sort(tasks);

  // Calculate the total waiting time
  int result = 0;
  for (int i = 0; i < N; ++i)
  {
    result += tasks[i] * (N - i);
  }

  std::cout << result << std::endl;

  return 0;
}
