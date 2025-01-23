#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool dfs(vector<vector<int>>& graph, int target) {
    vector<bool> visited(graph.size(), false);
    stack<int> s;

    // Automatically start from node 0
    int start = 0;
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        // If we find the target, return true
        if (current == target) {
            return true;
        }

        // Explore all neighbors
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }

    // If target is not found
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

    bool found = dfs(graph, target_node);

    if (found) {
        cout << "Node " << target_node << " was found during DFS traversal." << endl;
    } else {
        cout << "Node " << target_node << " was not found during DFS traversal." << endl;
    }

    return 0;
}
