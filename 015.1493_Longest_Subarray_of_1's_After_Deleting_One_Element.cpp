//1493. Longest Subarray of 1's After Deleting One Element - leetcode (medium) (acc : 68%)
//https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/submissions/1551373774
/*
Given a binary array nums, you should delete one element from it.
Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int zero = 0;
        int maxlen = 0;
        while (right < nums.size()) {
            if (nums[right] == 0) zero++;
            while (zero > 1) {//if there are more than 1 zero's we can shrink the window
                if (nums[left] == 0) zero--;
                left++;
            }
            maxlen = max(maxlen, right - left);//exclude atmost one zero
            right++;
        }
        return maxlen;
    }
};
