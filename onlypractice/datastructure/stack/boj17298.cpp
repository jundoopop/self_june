#include <iostream>

int main(void)
{
    int N = 0;
    std::cin >> N;

    int listOfNum[N]; // Generate an array
    for (int i = 0; i < N; i++)
        std::cin >> listOfNum[i]; // Allocate the numbers for N times

    for (int i = 0; i < N - 1; i++)
    {
        int temp = listOfNum[i];
        for (int j = i + 1; j < N; j++)
        {
            if (listOfNum[i] < listOfNum[j])
            { // If NGE exists
                listOfNum[i] = listOfNum[j];
                break;
            }
        }
        if (temp == listOfNum[i]) // If NGE doesn't exist, There's no change of listOfNum[i].
            listOfNum[i] = -1;
    }
    listOfNum[N - 1] = -1; // Last element is always changed to -1

    for (int i = 0; i < N - 1; i++)
        std::cout << listOfNum[i] << " "; // Print a number and whitespace

    std::cout << listOfNum[N - 1]; // Print the last element

    return 0;
}