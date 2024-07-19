# Input row & column,
# set the case of the 4 directions and judge if it is 1 or 0.


def dfs(entry_col, entry_row, visited):
    # Define the four directions: left, right, up, down
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    # Create a stack for DFS
    tracking = [(entry_col, entry_row)]

    while tracking:
        x, y = tracking.pop()

        # Exception handling: Index out of range
        if x < 0 or x >= column or y < 0 or y >= row:
            continue

        # Track the location of the cabbages
        if matrix[y][x] == 1 and visited[y][x] == 0:
            # Once the cabbage is found, change the value to 0
            matrix[y][x] = 0
            visited[y][x] = 1

            # Add adjacent cells to the stack
            for dx, dy in directions:
                new_x, new_y = x + dx, y + dy
                tracking.append((new_x, new_y))

    # Return True if at least one cabbage was found and processed
    return visited[entry_row][entry_col] == 1


# Input the number of the test cases
for _ in range(int(input())):
    # Input the row, column, and the number of cabbages
    column, row, num_of_cabbages = map(int, input().split())

    # Create the matrix
    matrix = [[0] * column for _ in range(row)]

    # Input the location of the cabbages
    for _ in range(num_of_cabbages):
        x, y = map(int, input().split())
        matrix[y][x] = 1

    # Create the count variable
    result = 0

    # Check the direction
    for i in range(column):
        for j in range(row):
            visited = [[0] * column for _ in range(row)]
            if dfs(i, j, visited):
                result += 1

    # Print the result
    print(result)
