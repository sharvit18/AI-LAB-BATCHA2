#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>>& graph, int target) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    int start = 0;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

   
        if (current == target) {
            return true;
        }

       
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

   
    return false;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},    // Node 0 connects to 1 and 2
        {0, 3, 4}, // Node 1 connects to 0, 3, and 4
        {0, 5},    // Node 2 connects to 0 and 5
        {1},       // Node 3 connects to 1
        {1},       // Node 4 connects to 1
        {2}        // Node 5 connects to 2
    };

    int target_node;
    cout << "Enter the node to search for: ";
    cin >> target_node;

    bool found = bfs(graph, target_node);

    if (found) {
        cout << "Node " << target_node << " was found during BFS traversal." << endl;
    } else {
        cout << "Node " << target_node << " was not found during BFS traversal." << endl;
    }

    return 0;
}
