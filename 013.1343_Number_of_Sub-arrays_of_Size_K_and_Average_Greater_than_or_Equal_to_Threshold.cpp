//1343. Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold - leetcode (medium) (acc : 69%)
//https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/description/?envType=problem-list-v2&envId=sliding-window
/*
Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.
*/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int cnt = 0;
        double sum = 0;
        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }
        if ((sum * 1.0)/k >= threshold * 1.0) cnt++;
        int n = arr.size();
        for (int i = k; i < n; i++) {
            sum += arr[i] - arr[i - k];
            if ((sum * 1.0)/k >= threshold * 1.0) cnt++;
        } 
        return cnt;
    }
};
