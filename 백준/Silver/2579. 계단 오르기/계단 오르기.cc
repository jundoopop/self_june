#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // Declare the variety for the number of cases
    int numOfStairs;
    std::cin >> numOfStairs;

    std::vector<int> stairs(numOfStairs);
    for (int i = 0; i < numOfStairs; ++i)
    {
        std::cin >> stairs[i];
    }

    // When the number of stairs are same or less than 2
    if (numOfStairs == 1)
    {
        std::cout << stairs[0] << std::endl;
        return 0;
    }
    if (numOfStairs == 2)
    {
        std::cout << stairs[0] + stairs[1] << std::endl;
        return 0;
    }

    // Initialise the dp array
    std::vector<int> dp(numOfStairs);

    // Allocate the dp results for counting
    dp[0] = stairs[0];
    dp[1] = stairs[0] + stairs[1];
    dp[2] = std::max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

    // Fill the dp array
    for (int i = 3; i < numOfStairs; ++i)
    {
        dp[i] = std::max(dp[i - 2], dp[i - 3] + stairs[i - 1]) + stairs[i];
    }

    // Get the optimised result
    std::cout << dp[numOfStairs - 1] << std::endl;
    return 0;
}
