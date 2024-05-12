#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

void searchWord(vector<vector<char>>& board, int x, int y, string& current, unordered_set<string>& dict, vector<string>& result, vector<vector<bool>>& visited) {
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return;
    if (visited[x][y]) return;

    current.push_back(board[x][y]);
    visited[x][y] = true;

    if (dict.find(current) != dict.end()) {
        if (find(result.begin(), result.end(), current) == result.end()) {
            result.push_back(current);
        }
    }

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx != 0 || dy != 0) {
                searchWord(board, x + dx, y + dy, current, dict, result, visited);
            }
        }
    }

    visited[x][y] = false;
    current.pop_back();
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    unordered_set<string> dict(words.begin(), words.end());
    vector<string> result;
    vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
    string current = "";

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            searchWord(board, i, j, current, dict, result, visited);
        }
    }

    return result;
}

int main() {
    vector<vector<char>> board = {
        {'G','I','Z'},
        {'U','E','K'},
        {'Q','S','E'}
    };
    vector<string> dictionary = {"GEEKS", "FOR", "QUIZ", "GO"};

    vector<string> foundWords = findWords(board, dictionary);

    if (foundWords.empty()) {
        cout << "-1" << endl;
    } else {
        sort(foundWords.begin(), foundWords.end());
        for (const string& word : foundWords) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
