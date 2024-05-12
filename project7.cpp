#include <iostream>
#include <vector>

using namespace std;

bool isSafe(int node, vector<vector<int>>& graph, vector<int>& colors, int col) {
    for (int k = 0; k < graph.size(); k++) {
        if (graph[node][k] && colors[k] == col) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>>& graph, int m, int node, vector<int>& colors) {
    if (node == graph.size()) {
        return true;
    }

    for (int i = 1; i <= m; i++) {
        if (isSafe(node, graph, colors, i)) {
            colors[node] = i;
            if (graphColoringUtil(graph, m, node + 1, colors)) {
                return true;
            }
            colors[node] = 0;
        }
    }
    return false;
}

bool graphColoring(vector<vector<int>>& graph, int m) {
    vector<int> colors(graph.size(), 0);
    return graphColoringUtil(graph, m, 0, colors);
}

int main() {
    int N = 4;
    int M = 3;
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    bool result = graphColoring(graph, M);
    cout << (result ? 1 : 0) << endl;

    return 0;
}
