#include <iostream>

typedef unsigned int uint;

int countSetBits(uint number) {
    int count = 0;
    while (number > 0) {
        count += number & 1;  // Check if the least significant bit is 1
        number >>= 1;         // Right shift the number by 1 bit
    }
    return count;
}

int main() {
    uint target;
    std::cin >> target;

    // Count the number of set bits in the target length
    int result = countSetBits(target);

    std::cout << result << std::endl;

    return 0;
}
