# https://www.acmicpc.net/problem/10799

"""
Iron Cut

Cutting Iron stick by laser.
Laser cuts vertically.

When putting iron stick, it is always overlapped vertically.
But the end of iron stick is not overlapped.

"""

iron_stick = input()  # String to iterate
result = 0  # Variable for output
stack_of_irons = (
    0  # Suppose this is a stack. This integer indicates the number of irons.
)

for idx in range(len(iron_stick)):  # Iterate all of the input by each character
    if iron_stick[idx] == "(":  # New iron starts.
        stack_of_irons += 1  # Push new iron to the stack.
    else:  # If iron_stick[idx] == ")"
        if iron_stick[idx - 1] == ")":  # If one iron ends
            stack_of_irons -= 1  # This iron is not cutted anymore
            result += 1  # Contain the last part of the abandoned one
        else:
            stack_of_irons -= 1  # If laser cut is detected
            result += stack_of_irons  # Add as the size of the stack
print(result)  # Print the result
