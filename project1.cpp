#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting {
    int start;
    int end;
};

bool compareMeeting(Meeting m1, Meeting m2) {
    return m1.end < m2.end;
}

int maxMeetings(vector<int> start, vector<int> end, int N) {
    vector<Meeting> meetings(N);
    for (int i = 0; i < N; ++i) {
        meetings[i].start = start[i];
        meetings[i].end = end[i];
    }

    sort(meetings.begin(), meetings.end(), compareMeeting);

    int lastEndTime = 0;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (meetings[i].start > lastEndTime) {
            lastEndTime = meetings[i].end;
            ++count;
        }
    }
    return count;
}

int main() {
    // Example 1
    int N1 = 6;
    vector<int> start1 = {1, 3, 0, 5, 8, 5};
    vector<int> end1 = {2, 4, 6, 7, 9, 9};
    cout << "Maximum number of meetings (Example 1): " << maxMeetings(start1, end1, N1) << endl;

    // Example 2
    int N2 = 3;
    vector<int> start2 = {10, 12, 20};
    vector<int> end2 = {20, 25, 30};
    cout << "Maximum number of meetings (Example 2): " << maxMeetings(start2, end2, N2) << endl;

    return 0;
}
