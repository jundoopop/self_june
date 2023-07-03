# https://www.acmicpc.net/problem/1874

"""
Stacked Array

push, pop, LIFO 
-> Those three features are characters that Stack data has.

- Assuming implementing an array same as the input array.
- From the ascending array.

If the number of pushed numbers are more than one, 
but requires ascending order -> It cannot be implemented.
"""

list_of_pushed_number = (
    []
)  # list_of_pushed_number is a list to contain the temporary numbers
stack = []  # Stack is for printing result
targeted_number = 1  # targeted_number is for a comparison with the number input
for i in range(int(input())):  # int(input()): n (iteration)
    number = int(input())  # This number consists a stack
    while targeted_number <= number:  # If list_of_pushed_number is needed to be added
        list_of_pushed_number.append(targeted_number)
        stack.append("+")  # Record the history of push
        targeted_number += 1  # Step to next targeted number

    # This print is for checking if list works correctly
    # print(f"Temp Stack: {list_of_pushed_number}")

    if number == list_of_pushed_number.pop():  # If the sequence of stack is valid
        stack.append("-")  # Record the history of pop
    else:  # If it is invalid
        print("NO")  # Print 'NO' and break the loop
        break

else:  # When loop successfully iterated to the end
    print("\n".join(stack))  # Print by using join method.
