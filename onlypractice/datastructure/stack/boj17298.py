# https://www.acmicpc.net/problem/17298

"""
Larger number at right:
Compare with current number in list,
with the numbers on the right of the current number.

If larger one exists, Print the number.
If not exists, print -1.
"""

N = int(input())  # Length of the list of numbers
list_of_numbers = input().split()

for i in range(N - 1):
    for j in range(i + 1, N):
        if int(list_of_numbers[i]) < int(list_of_numbers[j]):
            list_of_numbers[i] = list_of_numbers[j]
            break
    else:
        list_of_numbers[i] = "-1"

list_of_numbers[-1] = "-1"
print(" ".join(list_of_numbers))  # Print the result.
