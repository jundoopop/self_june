# Get the length of the list
lengthOfList = int(input())

# Get the list of numbers
listOfNumbers = [int(x) for x in input().split()]


ascendingList = [1 for _ in range(lengthOfList)]
descendingList = [1 for _ in range(lengthOfList)]

for idx in range(lengthOfList - 1):
    # In the scope of ascending sequence
    if listOfNumbers[idx + 1] > listOfNumbers[idx]:
        ascendingList[idx + 1] += ascendingList[idx]
    # In the scope of descending sequence
    elif listOfNumbers[idx + 1] < listOfNumbers[idx]:
        descendingList[idx + 1] += descendingList[idx]

    else:
        ascendingList[idx + 1] += ascendingList[idx]
        descendingList[idx + 1] += descendingList[idx]

# Print the maximum number of numbers.
print(max(max(ascendingList), max(descendingList)))
