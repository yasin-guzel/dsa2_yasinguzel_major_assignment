#include <iostream>
#include <vector>
#include <string>

using namespace std;

void backtrackIPAddresses(const string& s, int start, int partCount, string currentIP, vector<string>& result) {
    if (partCount == 4 && start == s.size()) {
        result.push_back(currentIP.substr(0, currentIP.length() - 1));
        return;
    }
    if (partCount == 4 && start != s.size()) {
        return;
    }

    for (int len = 1; len <= 3 && start + len <= s.size(); len++) {
        string segment = s.substr(start, len);
        int value = stoi(segment);

        if ((segment.length() > 1 && segment[0] == '0') || value > 255) {
            break;
        }

        backtrackIPAddresses(s, start + len, partCount + 1, currentIP + segment + '.', result);
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    if (s.length() < 4 || s.length() > 12) return result;
    backtrackIPAddresses(s, 0, 0, "", result);
    return result;
}

int main() {
    string input = "25525511135";
    vector<string> validIPs = restoreIpAddresses(input);
    if (validIPs.empty()) {
        cout << "-1" << endl;
    } else {
        for (const string& ip : validIPs) {
            cout << ip << endl;
        }
    }
    
    input = "56";
    validIPs = restoreIpAddresses(input);
    if (validIPs.empty()) {
        cout << "-1" << endl;
    } else {
        for (const string& ip : validIPs) {
            cout << ip << endl;
        }
    }
    return 0;
}
