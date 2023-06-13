# https://www.acmicpc.net/problem/10845

"""
Queue Implementation

- Queue is FIFO.
- Six commands should be implemented:
1) push X: push X to the queue list.
2) pop: pop the first element of the queue list and print. If the queue is empty, print -1.
3) size: print the size of the queue list.
4) empty: print 1 if the queue is empty, otherwise 0.
5) front: print the first element of the queue list. If the queue is empty, print -1.
6) back: print the last element of the queue list. If the queue is empty, print -1.

"""

import sys
from collections import deque

# input() is slow, so use sys.stdin.readline()
input = sys.stdin.readline

# Initialize the list
queue_list = deque()
# iter_number decides how many times to iterate the loop
iter_number = int(input())

# repeats for the times of iter_number
for i in range(iter_number):
    # Put command
    command = input().split()

    # front: first element of the list
    if command[0][0] == "f":
        print(queue_list[0]) if len(queue_list) != 0 else print(-1)

    # back: last element of the list
    if command[0][0] == "b":
        print(queue_list[-1]) if len(queue_list) != 0 else print(-1)

    # size: length of the list
    if command[0][0] == "s":
        print(len(queue_list))

    # if the length of the list is 0 or not
    if command[0][0] == "e":
        print(1) if len(queue_list) == 0 else print(0)

    # pop method -> queue is fifo.
    if command[0] == "pop":
        # deque library method popleft()
        print(queue_list.popleft()) if len(queue_list) != 0 else print(-1)

    # The case 'push' which is last
    if command[0] == "push":
        queue_list.append(command[1])
