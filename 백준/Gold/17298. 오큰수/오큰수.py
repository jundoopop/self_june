iterating_number = int(input())
list_to_sort = list(map(int, input().split()))

result = [-1 for i in range(iterating_number)]
stack = [0] # This '0' displays index

for i in range(1, iterating_number):
    while stack and list_to_sort[stack[-1]] < list_to_sort[i]:
        result[stack.pop()] = list_to_sort[i]
    stack.append(i) # Append indices


print(*result) # Asterisk unpacks an array
