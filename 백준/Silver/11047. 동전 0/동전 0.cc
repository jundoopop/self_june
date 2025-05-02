#include <iostream>
#include <vector>

int main()
{
     int howManyTypes, totalAmount; // Number of coin types and total amount
     std::cin >> howManyTypes >> totalAmount;

     // Stock the types of the coins
     std::vector<int> coins(howManyTypes);
     for (int i = 0; i < howManyTypes; ++i)
     {
          std::cin >> coins[i];
     }

     // Count the cases
     int result = 0;
     for (int i = howManyTypes - 1; i >= 0; --i)
     {
          result += totalAmount / coins[i];
          totalAmount %= coins[i];
     }

     std::cout << result << '\n';
     return 0;
}
