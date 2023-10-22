#include <deque>
#include <iostream>
using namespace std;

int main(void) {

  int top_number, turn = 0; // Initialise a number
  cin >> top_number;        // Input a number

  deque<int> deck{}; // Declare a deque to control the numbers

  for (int i = 1; i < top_number + 1; i++)
    deck.push_back(i); // Stack a number

  while (deck.empty() == false) {
    turn += 1;
    if (turn % 2 == 0) {            // After a card abandoned
      deck.push_back(deck.front()); // Send a card to the backward
      deck.pop_front();

    } else { // Odd turn: remove and print a card
      cout << deck.front() << " ";
      deck.pop_front();
    }
  }

  return 0; // End a program
}
