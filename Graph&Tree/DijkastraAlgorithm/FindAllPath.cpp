#include <bits/stdc++.h>
using namespace std;

void printPath(const vector<int>& path) {
    for (int i = 0; i < path.size(); i++) {
        cout << char('A' + path[i]);
        if (i != path.size() - 1) {
            cout << " -> ";
        }
    }
    cout << endl;
}

void findAllPathsUtil(const vector<vector<int>>& graph, int u, int d, vector<bool>& visited, vector<int>& path) {
    visited[u] = true;
    path.push_back(u);

    if (u == d) {
        printPath(path);
    } else {
        for (int v = 0; v < graph.size(); v++) {
            if (graph[u][v] && !visited[v]) {
                findAllPathsUtil(graph, v, d, visited, path);
            }
        }
    }

    path.pop_back();
    visited[u] = false;
}

void findAllPaths(const vector<vector<int>>& graph, int src, int dest) {
    vector<bool> visited(graph.size(), false);
    vector<int> path;
    findAllPathsUtil(graph, src, dest, visited, path);
}

int main() {
    cout << "Enter the number of nodes: ";
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the source and destination: ";
    char s, d;
    cin >> s >> d;
    int src = s - 'A';
    int dest = d - 'A';

    cout << "All paths from " << s << " to " << d << " are:" << endl;
    findAllPaths(graph, src, dest);

    return 0;
}
