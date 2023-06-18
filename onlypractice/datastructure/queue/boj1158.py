"""
Josephus

order_of_list(<= number_of_people)

ex) (7, 3)
<3, 6, 2, 7, 5, 1, 4>
"""

number_of_people, order_of_list = map(int, input().split())

list_of_numbers = [str(i + 1) for i in range(number_of_people)]  # Allocate the numbers
result = []  # This list is for output
idx = order_of_list - 1  # Entry point of the Josephus


while (
    len(list_of_numbers) > 1
):  # If the last element is contained, index error is occured
    # print(f"Targeted number: {list_of_numbers[idx]}, Targeted index: {idx}")
    result.append(list_of_numbers.pop(idx))
    idx = (idx + order_of_list) % len(
        list_of_numbers
    ) - 1  # When the list is popped, one of the length of list is decreased.
    if idx == -1:  # Adjust a value of the index to the end of the list
        idx = len(list_of_numbers) - 1

result.append(list_of_numbers[0])  # Add the last element

print(f"<{', '.join(result)}>")  # Print in the form that the problem required
