#include <iostream>
#include <vector>

void dfs(int node, std::vector<bool> &visited, const std::vector<std::vector<int>> &graph)
{
     // It's true when such node is visited
     visited[node] = true;
     for (int neighbor : graph[node])
     {
          // Traverse by dfs with recursion
          if (!visited[neighbor])
          {
               dfs(neighbor, visited, graph);
          }
     }
}

int main()
{
     int numOfNodes, numOfEdges;
     std::cin >> numOfNodes >> numOfEdges;

     // Declare a vector of graph, which nests other vector to implement the shape of graph
     std::vector<std::vector<int>> graph(numOfNodes + 1);
     for (int i = 0; i < numOfEdges; ++i)
     {
          int from, to;
          // Set a node
          std::cin >> from >> to;
          // Save elements of connection
          graph[from].push_back(to);
          graph[to].push_back(from);
     }

     std::vector<bool> visited(numOfNodes + 1, false);
     int result = 0;

     // Traverse components
     for (int i = 1; i <= numOfNodes; ++i)
     {

          if (!visited[i])
          {
               dfs(i, visited, graph);
               result += 1;
          }
     }

     std::cout << result << std::endl;
     return 0;
}
