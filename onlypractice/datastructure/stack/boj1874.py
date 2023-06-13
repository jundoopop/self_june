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


result = []  # Result is for printing '+' and '-'
temp = []  # Temp is stack.
list_of_popped_numbers = (
    []
)  # This list is needed for the condition to push a number to the stack.

last_num, status = 0, 1
for i in range(int(input())):  # Iterate as the number which is entered
    target = int(input())

    if target >= last_num:  # Compare with target 'target' and 'last_num'.
        for j in range(
            last_num + 1, target + 1
        ):  # When 'target' is same or larger than 'last_num'
            if (
                j not in list_of_popped_numbers
            ):  # the number j is not contained in the list_of_popped_numbers.
                temp.append(
                    j
                )  # Append 'j' to the list 'temp', and record the append to the result."
                result.append("+")

    if temp[-1] == target:
        print(f"temp[-1] {temp[-1]} equals to the target {target}.")
        list_of_popped_numbers.append(temp.pop())
        result.append("-")

    elif temp[-1] > target:  # The array which is targeted is not able to be created.
        status = 0
        print("NO")
        break  # End the loop

    last_num = target  # Declare the next last_num for comparison with the next target


if status == 1:  # Status 1 means making a targeted list with push and pop is able.
    for operator in result:
        print(operator)
