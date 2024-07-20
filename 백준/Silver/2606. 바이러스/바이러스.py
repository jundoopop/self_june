volume = int(input())  # Number of computers

# Initialize the network as an adjacency list
network = [[] for _ in range(volume + 1)]

# Read and store the connections
for _ in range(int(input())):
    start, end = map(int, input().split())
    network[start].append(end)
    network[end].append(start)  # Add the reverse connection


def dfs(start):
    visited = set()
    stack = [start]

    while stack:
        node = stack.pop()
        if node not in visited:
            visited.add(node)
            stack.extend(
                neighbour for neighbour in network[node] if neighbour not in visited
            )

    return len(visited) - 1  # Subtract 1 to exclude the start node


# Print the result
print(dfs(1))
