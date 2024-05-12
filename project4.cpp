#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair {
    int first;
    int second;
};

bool comparePairs(const Pair& p1, const Pair& p2) {
    return p1.second < p2.second;
}

int maxChainLen(vector<Pair>& pairs, int N) {
    sort(pairs.begin(), pairs.end(), comparePairs);

    int chainLen = 1;
    int lastEnd = pairs[0].second;

    for (int i = 1; i < N; i++) {
        if (pairs[i].first > lastEnd) {
            chainLen++;
            lastEnd = pairs[i].second;
        }
    }

    return chainLen;
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
