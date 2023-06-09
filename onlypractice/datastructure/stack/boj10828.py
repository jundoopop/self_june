# https://www.acmicpc.net/problem/10828

# stack implmlentation

"""
The stack stores integers by input.
The stack has the following commands:
    push X: Push the integer 'X' into the stack
    pop: Pop the top element of the stack and print. If the stack is empty, print -1
    size: Print the size of the stack
    empty: Print 1 if the stack is empty, otherwise 0
    top: Print the top element of the stack
"""

import sys

# input() is slow, so use sys.stdin.readline()
input = sys.stdin.readline

# Initialize the list
stack_list = []
# iter_number decides how many times to iterate the loop
iter_number = int(input())

# repeats for the times of iter_number
for i in range(iter_number):
    # Put command
    command = input().split()

    # top: last element of the list
    if command[0] == "top":
        print(stack_list[-1]) if len(stack_list) != 0 else print(-1)

    # size: length of the list
    elif command[0] == "size":
        print(len(stack_list))

    # if the length of the list is 0 or not
    elif command[0] == "empty":
        print(1) if len(stack_list) == 0 else print(0)

    # pop method
    elif command[0] == "pop":
        print(stack_list.pop()) if len(stack_list) != 0 else print(-1)

    # The case 'push' which is last
    else:
        stack_list.append(command[1])
