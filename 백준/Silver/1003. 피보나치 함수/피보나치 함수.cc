#include <iostream>
#include <vector>

using namespace std;

int main()
{
     // Array to contain each results
     // 0 <= N <= 41 -> 41 cases
     vector<vector<int>> zeroAndOne(41);

     // Fibonacci(0) and Fibonacci(1)
     zeroAndOne[0] = {1, 0};
     zeroAndOne[1] = {0, 1};

     for (int i = 2; i <= 40; i++)
     { // Fibonacci iteration
          zeroAndOne[i] = {zeroAndOne[i - 1][0] + zeroAndOne[i - 2][0],
                           zeroAndOne[i - 1][1] + zeroAndOne[i - 2][1]};
     }

     int testCase; // T
     cin >> testCase;

          while (testCase-- > 0) // Output
     {
          int num;
          cin >> num;

          cout << zeroAndOne[num][0] << " " << zeroAndOne[num][1] << "\n";
     }

     return 0;
}
