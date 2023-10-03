"""
Array A[N], B[N]

Get minimum S
elements in B should remain their indices

Match smallest A element and largest B element
"""
number_of_elements = int(input())

array_a = list(map(int, input().split()))  # Declare an array 'a'
array_b = list(map(int, input().split()))  # Declare an array 'b'

result = 0
for i in range(number_of_elements):
    temp_a, temp_b = min(array_a), max(array_b)  # Way to get minimum value
    result += temp_a * temp_b  # Add the production of those two numbers
    array_a.remove(temp_a)  # Remove for the next computation
    array_b.remove(temp_b)

print(result)
