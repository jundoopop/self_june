# Get the length of the list
length_of_list = int(input())

# Get the list of numbers
list_of_numbers = [int(x) for x in input().split()]

# Initialize lists to track ascending and descending sequence lengths
ascending_lengths = [1] * length_of_list
descending_lengths = [1] * length_of_list

# Iterate through the list to fill the ascending and descending lists
for i in range(1, length_of_list):
    # Count the case of ascending
    if list_of_numbers[i] > list_of_numbers[i - 1]:
        ascending_lengths[i] = ascending_lengths[i - 1] + 1
    # Count the case of descending
    elif list_of_numbers[i] < list_of_numbers[i - 1]:
        descending_lengths[i] = descending_lengths[i - 1] + 1
    # If numbers are equal, maintain the sequence lengths
    else:
        ascending_lengths[i] = ascending_lengths[i - 1] + 1
        descending_lengths[i] = descending_lengths[i - 1] + 1

# Print the maximum length found in either ascending or descending sequences
print(max(max(ascending_lengths), max(descending_lengths)))
