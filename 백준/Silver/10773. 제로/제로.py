number_of_integers = int(input()) # Boss will say for these times of number
array_for_result = []

for i in range(number_of_integers): # Iterate
    what_boss_said = int(input())
    if what_boss_said == 0: # If the input is 0, the latest number would be removed
        array_for_result.pop() # Remove the number
    else:
        array_for_result.append(what_boss_said) # Add the number to the list

print(sum(array_for_result))