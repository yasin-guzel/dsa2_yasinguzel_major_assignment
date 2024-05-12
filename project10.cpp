#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int kthElement(vector<int>& arr1, vector<int>& arr2, int N, int M, int k) {
    if (N > M) return kthElement(arr2, arr1, M, N, k);

    int low = max(0, k - M), high = min(k, N);

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;
        int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int right1 = (cut1 == N) ? INT_MAX : arr1[cut1];
        int right2 = (cut2 == M) ? INT_MAX : arr2[cut2];

        if (left1 <= right2 && left2 <= right1) {
            return max(left1, left2);
        } else if (left1 > right2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }

    return 1;
}

int main() {
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int k = 5;

    cout << "The " << k << "th element is " << kthElement(arr1, arr2, arr1.size(), arr2.size(), k) << endl;

    return 0;
}
