#include <iostream>
#include <vector>
#include <algorithm>

// This function checks if the brackets in the input string are balanced
int chooseMinOne(int N)
{
    std::vector<int> dp(N + 1, 0);

    // Iterate from 2 to N for choose min value
    for (int i = 2; i <= N; ++i)
    {
        // Choose a minimum value among deducing by 1, dividing by 2 and 3
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)
        {
            dp[i] = std::min(dp[i], dp[i / 2] + 1);
        }
        if (i % 3 == 0)
        {
            dp[i] = std::min(dp[i], dp[i / 3] + 1);
        }
    }

    return dp[N];
}

int main()
{
    // Get a value to compute by input
    int numToDivide;
    std::cin >> numToDivide;

    // Execute a function and display it
    int result = chooseMinOne(numToDivide);
    std::cout << result << std::endl;

    return 0;
}
