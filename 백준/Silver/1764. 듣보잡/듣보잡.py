"""
First listen & seen

Return the cases which satisfy both conditions
"""

non_listen, non_seen = map(int, input().split())  # First line for input
ear_list, both_list = {}, []
cnt = 0

for i in range(non_listen):  # Iterate for the number of non listen people
    ear_list[input()] = 1  # Make a dictionary with the name as key

for i in range(non_seen):  # Iterate for the number of non seen people
    name = input()
    if ear_list.get(name) == 1: 
        # If the name is in the dictionary append a name to both_list
        both_list.append(name)  
        cnt += 1

both_list.sort()  # Sort the list to dictionary order
print(cnt)  # Print the number of cases
for i in range(cnt):  # Print the cases
    print(both_list[i])
