#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

bool compareJob(const Job& j1, const Job& j2) {
    return j1.deadline < j2.deadline;
}

int JobScheduling(vector<Job>& jobs, int N) {
    sort(jobs.begin(), jobs.end(), compareJob);

    vector<int> dp(N);

    dp[0] = jobs[0].profit;

    for (int i = 1; i < N; i++) {
        int inclProf = jobs[i].profit;

        int latestNonConflict = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (jobs[j].deadline <= jobs[i].deadline) {
                latestNonConflict = j;
                break;
            }
        }

        if (latestNonConflict != -1)
            inclProf += dp[latestNonConflict];

        dp[i] = max(dp[i - 1], inclProf);
    }

    return dp[N - 1];
}

int main() {
    vector<Job> jobs = {
        {1, 2, 100}, {2, 1, 50}, {3, 2, 20}, {4, 3, 60}, {5, 3, 30}
    };
    int N = jobs.size();

    int maxProfit = JobScheduling(jobs, N);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
