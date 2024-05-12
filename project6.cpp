#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solveMaze(vector<vector<int>>& maze, int x, int y, int N, vector<string>& paths, string path) {
    if (x < 0 || x >= N || y < 0 || y >= N || maze[x][y] == 0) {
        return;
    }
    
    if (x == N - 1 && y == N - 1) {
        paths.push_back(path);
        return;
    }

    maze[x][y] = 0;
    if (x > 0) {
        solveMaze(maze, x - 1, y, N, paths, path + 'U');
    }
    if (x < N - 1) {
        solveMaze(maze, x + 1, y, N, paths, path + 'D');
    }
    if (y > 0) {
        solveMaze(maze, x, y - 1, N, paths, path + 'L');
    }
    if (y < N - 1) {
        solveMaze(maze, x, y + 1, N, paths, path + 'R');
    }

    maze[x][y] = 1;
}

vector<string> findPaths(vector<vector<int>>& maze, int N) {
    vector<string> paths;
    if (maze[0][0] == 0) return paths;
    string path = "";
    solveMaze(maze, 0, 0, N, paths, path);
    return paths;
}

int main() {
    int N = 4;
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> paths = findPaths(maze, N);
    if (paths.empty()) {
        cout << -1 << endl;
    } else {
        for (const string& p : paths) {
            cout << p << " ";
        }
        cout << endl;
    }

    return 0;
}
