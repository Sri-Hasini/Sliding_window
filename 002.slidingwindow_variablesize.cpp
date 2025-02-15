// Sliding window with variable sized window
#include <bits/stdc++.h>
using namespace std;

int max_lenarr(vector<int>&nums, int k)  {
    int left = 0;
    int windowSum = nums[0];
    int maxLen = 0;
    for (int right = 0; right < nums.size(); right++) {
        while (windowSum >= k) {
            windowSum -= nums[left];
            left += 1;
        }
        maxLen = max(maxLen, right - left + 1);
        if (right < nums.size() - 1) {
            windowSum += nums[right + 1];
        }
    }
    return maxLen;
}

int main() {
    int n;
    cin >> n;
    vector <int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int sum;
    cin >> sum;
    int ans = max_lenarr(nums, sum);
    cout << "Longest subarray with sum less than k is : " << ans;
}

//input
/*
5
1 2 3 4 5
10
*/

//output
/*
Longest subarray with sum less than k is : 3
*/
