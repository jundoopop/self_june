# https://www.acmicpc.net/problem/10866

"""
Deck (Deque) Implementation

- Deque.
- Eight commands should be implemented:
1) push_front X: push X to the last of the queue list.
2) push_back X: push X to the first of the queue list.
3) pop_front: pop the first element of the queue list and print. If the queue is empty, print -1.
4) pop_back: pop the last element of the queue list and print. If the queue is empty, print -1.
5) size: print the size of the queue list.
6) empty: print 1 if the queue is empty, otherwise 0.
7) front: print the first element of the queue list. If the queue is empty, print -1.
8) back: print the last element of the queue list. If the queue is empty, print -1.

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
    if command[0] == "front":
        print(queue_list[0]) if len(queue_list) != 0 else print(-1)

    # back: last element of the list
    if command[0] == "back":
        print(queue_list[-1]) if len(queue_list) != 0 else print(-1)

    # size: length of the list
    if command[0] == "size":
        print(len(queue_list))

    # if the length of the list is 0 or not
    if command[0] == "empty":
        print(1) if len(queue_list) == 0 else print(0)

    # pop method -> queue is fifo.
    if command[0] == "pop_front":
        # deque library method popleft()
        print(queue_list.popleft()) if len(queue_list) != 0 else print(-1)

    if command[0] == "pop_back":
        # deque library method popleft()
        print(queue_list.pop()) if len(queue_list) != 0 else print(-1)

    # The case 'push' which is for the front
    if command[0] == "push_back":
        queue_list.append(command[1])

    # The case 'push' which is for the last
    if command[0] == "push_front":
        queue_list.appendleft(command[1])
