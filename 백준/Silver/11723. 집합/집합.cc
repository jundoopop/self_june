#include <iostream>
#include <string>

int main()
{
    // IO performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    // Number to iterate
    int M;
    std::cin >> M;

    std::string operation;
    int setBit = 0; // Bitmask should be initialised as zero

    while (M-- > 0) // Loop
    {
        std::cin >> operation; // Choose one of six set methods
        int x;

        if (operation == "add")
        {
            std::cin >> x;
            setBit |= (1 << x);
        }
        else if (operation == "remove")
        {
            std::cin >> x;
            setBit &= ~(1 << x); // Clearing a bit
        }
        else if (operation == "check")
        {
            std::cin >> x;
            // Bitwise AND
            // Prints 1 if both are 1, 0 if one of them is 0
            std::cout << (setBit & (1 << x) ? 1 : 0) << '\n';
        }
        else if (operation == "toggle")
        {
            std::cin >> x;
            setBit ^= (1 << x); // XOR
        }
        else if (operation == "all")
        {
            // 1.....0_2 - 1_2 = 1111...11_2
            setBit = (1 << 21) - 1;
        }
        else if (operation == "empty")
        {
            setBit = 0;
        }
    }

    return 0;
}