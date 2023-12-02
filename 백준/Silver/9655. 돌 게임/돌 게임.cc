

/*
This problem is categorised as DP,
but this problem define two choices with only odd numbers.
So all cases of games have same results 
because all the number of turns are odd if input number is an odd,
or even number of turns when even number is put to input value.
*/

#include <iostream>

int main(void) {

  // Define a number of whole samples
  int numberOfRocks;
  std::cin >> numberOfRocks;

  // If numberOfRocks is an even number, CY wins.
  if (numberOfRocks % 2 == 0)
    std::cout << "CY";
  // Else, if numberOfRocks is an odd number, SK wins.
  else
    std::cout << "SK";

  return 0;
}
