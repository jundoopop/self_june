"""
Fibonacci sequence:
f(n) = f(n-2) + f(n-1)
f(0) = 0, f(1) = 1
f(2) = f(0) + f(1) = 1
f(3) = f(1) + f(2) = 2
f(4) = f(2) + f(3) = 3
f(5) = f(3) + f(4) = 5
...
"""

for i in range(int(input())):  # Iterate
    test_number = int(input())  # Number to count the numbers of zero and one
    fibonacci_results = [[1, 0], [0, 1]]

    if test_number == 0:  # If test number is 0
        print(f"1 0")
        continue

    if test_number == 1:  # If test number is 1
        print(f"0 1")
        continue

    for j in range(2, test_number + 1):  # if test tumber is same or larger than 2
        fibonacci_results.append(
            [
                fibonacci_results[-2][0] + fibonacci_results[-1][0],
                fibonacci_results[-2][1] + fibonacci_results[-1][1],
            ]  # Add the results of temporary computation
        )

    print(f"{fibonacci_results[-1][0]} {fibonacci_results[-1][1]}")  # Print a result
