#include <iostream>
#include <vector>

using namespace std;

int numberSequence(int m, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int j = 1; j <= m; ++j) {
        dp[1][j] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = j * 2; k <= m; k += j) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    int count = 0;
    for (int j = 1; j <= m; ++j) {
        count += dp[n][j];
    }

    return count;
}

int main() {
    int m = 10;
    int n = 4;

    cout << "Total special sequences of length " << n << " with max value " << m << ": " << numberSequence(m, n) << endl;

    return 0;
}
