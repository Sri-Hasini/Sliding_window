//Finding the Subarray with Minimum Sum of Size K - codechef (easy)
//https://www.codechef.com/practice/course/two-pointers/SLIDINGWINDO/problems/SLDW0105?tab=statement
/*
You are given an array of integers and you need to find a subarray of size K that has the minimum sum in all the subarray of size K.
*/
#include <bits/stdc++.h>
using namespace std;

long long findMinSumSubarray(int n, int k, vector<int>& arr) {
    long long min_sum = LLONG_MAX;
    long long cur_sum = 0;
    for (int i = 0; i < k; i++) {
        cur_sum += arr[i];
    }
    min_sum = cur_sum;
    for (int i = k; i < n; i++) {
        cur_sum += arr[i] - arr[i - k];
        if (min_sum > cur_sum) min_sum = cur_sum;
    }
    return min_sum;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << findMinSumSubarray(n, k, arr) << endl;
    return 0;
}
