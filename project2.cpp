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
    return j1.profit > j2.profit;
}

vector<int> JobScheduling(vector<Job>& jobs, int N) {
    sort(jobs.begin(), jobs.end(), compareJob);

    int maxDeadline = 0;
    for (int i = 0; i < N; ++i) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    vector<int> slot(maxDeadline + 1, -1);  // Initialize all slots to -1 (free)

    int countJobs = 0;
    int jobProfit = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = jobs[i].deadline; j > 0; --j) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id; 
                countJobs++; 
                jobProfit += jobs[i].profit; 
                break;
            }
        }
    }

    return {countJobs, jobProfit};
}

int main() {
    vector<Job> jobs = {
        {1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}
    };
    int N = jobs.size();

    vector<int> result = JobScheduling(jobs, N);
    cout << "Jobs done: " << result[0] << ", Max Profit: " << result[1] << endl;

    return 0;
}
