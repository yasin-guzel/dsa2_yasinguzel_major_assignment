#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool isPossible(vector<int>& books, int N, int M, int maxLoad) {
    int studentsRequired = 1, currentSum = 0;

    for (int pages : books) {
        if (pages > maxLoad) return false;

        if (currentSum + pages > maxLoad) {
            studentsRequired++;
            currentSum = pages;

            if (studentsRequired > M) return false;
        } else {
            currentSum += pages;
        }
    }
    return true;
}

int findPages(vector<int>& books, int N, int M) {
    if (M > N) return -1;

    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(books, N, M, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    vector<int> books = {12, 34, 67, 90};
    int N = books.size();
    int M = 2;

    cout << "The minimum of the maximum pages that can be allocated to a student is " << findPages(books, N, M) << endl;

    return 0;
}
