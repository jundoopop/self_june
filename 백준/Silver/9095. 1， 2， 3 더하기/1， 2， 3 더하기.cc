#include <iostream>
#include <vector>

int main()
{
     // Initialize the dp vector with base cases
     std::vector<int> dp = {0, 1, 2, 4};

     int iteration;
     std::cin >> iteration; // Read the number of test cases

     while (iteration--)
     {
          int n;
          std::cin >> n;

          // Validate input
          if (n <= 0 || n > 10)
          {
               std::cerr << "Please enter a positive integer between 1 and 10." << std::endl;
               return 1;
          }

          // If n is less than 4, print the prepared value
          if (n < 4)
          {
               std::cout << dp[n] << std::endl;
          }
          else
          {
               // Compute the number of ways for n >= 4
               if (dp.size() <= n)
               {
                    dp.resize(n + 1); // Resize to accommodate dp[n]
                    for (std::size_t i = 4; i <= static_cast<std::size_t>(n); ++i)
                    {
                         dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
                    }
               }
               std::cout << dp[n] << std::endl;
          }
     }

     return 0;
}
