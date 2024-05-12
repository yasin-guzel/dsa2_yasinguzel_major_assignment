#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int first;
    int second;
};

bool comparePairs(const Pair& p1, const Pair& p2) {
    return p1.first < p2.first;
}

int maxChainLen(vector<Pair>& pairs, int N) {
    sort(pairs.begin(), pairs.end(), comparePairs);

    vector<int> dp(N, 1);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (pairs[j].second < pairs[i].first && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int maxLen = 0;
    for (int i = 0; i < N; i++) {
        if (maxLen < dp[i]) {
            maxLen = dp[i];
        }
    }

    return maxLen;
}

int main() {
    vector<Pair> pairs = {
        {5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90}
    };
    int N = pairs.size();

    int longestChain = maxChainLen(pairs, N);
    cout << "The longest chain length is: " << longestChain << endl;

    return 0;
}
