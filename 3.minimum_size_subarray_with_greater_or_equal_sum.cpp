// Minimum sized subarray with sum greater than or equal the target - leetcode (acc: 48%)(medium)
//https://leetcode.com/problems/minimum-size-subarray-sum/
/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, sum = 0;
        int ans = INT_MAX;
        while (right < nums.size()) {
            sum += nums[right];
            while (sum >= target) {
                ans = min(right - left + 1, ans);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        if (ans == INT_MAX) return 0;
        return ans;
    }
};
