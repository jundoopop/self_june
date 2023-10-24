#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {

  stack<int> number_stack; // Declare a stack

  int num_to_iterate = 0;
  (void)scanf("%d", &num_to_iterate); // Number to iterate

  for (int i = 0; i < num_to_iterate; i++) {
    int command = 0;
    (void)scanf("%d", &command);

    if (command == 1) { // Command 1
      int number_to_push = 0;
      (void)scanf("%d", &number_to_push);
      number_stack.push(number_to_push); // Push a number
    }

    else if (command == 2) { // Command 2
      if (number_stack.empty()) {
        printf("%d\n", -1);
      } else {
        printf("%d\n", number_stack.top()); // Print top value of stack
        number_stack.pop();
      }
    }

    else if (command == 3) {               // Command 3
      printf("%d\n", number_stack.size()); // Print a size of stack
    }

    else if (command == 4) { // Command 4
      printf("%d\n",
             int(number_stack.empty())); // Print 1 if stack is empty, 0 if not
    }

    else if (command == 5) {                // Command 5
      if (number_stack.empty())             // If a stack is empty
        printf("%d\n", -1);                 // Print -1
      else                                  // If it contains integers
        printf("%d\n", number_stack.top()); // Print a top of stack
    }
  }

  return 0; // End a program
}
