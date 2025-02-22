#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool dfs(vector<vector<int>>& graph, int target) {
    vector<bool> visited(graph.size(), false);
    stack<int> s;

   
    int start = 0;
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int current = s.top();
        s.pop();

       
        if (current == target) {
            return true;
        }

        
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }

    
    return false;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},    
        {0, 3, 4},
        {0, 5},    
        {1},      
        {1},      
        {2}        
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
