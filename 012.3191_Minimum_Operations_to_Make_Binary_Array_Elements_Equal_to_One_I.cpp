//3191. Minimum Operations to Make Binary Array Elements Equal to One I - leetcode (medium) (acc : )
//https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/?envType=problem-list-v2&envId=sliding-window
/*
You are given a binary array nums.
You can do the following operation on the array any number of times (possibly zero):
Choose any 3 consecutive elements from the array and flip all of them.
Flipping an element means changing its value from 0 to 1, and from 1 to 0.
Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = -1, cnt = 0;
        for (int i = 0; i <= nums.size() - 3; i++) {//running this upto size - 3
            if (nums[i] == 0) {//if the current element is 0, we can toggle ith term and i+1 and i+2 also
                nums[i] = 1;
                if (!nums[i + 1]) nums[i + 1] = 1;
                else nums[i + 1] = 0;
                if (!nums[i + 2]) nums[i + 2] = 1;
                else nums[i + 2] = 0;
                cnt++;//representing that operation has performed
            }
        }
        if (!nums[nums.size() - 2] || !nums[nums.size() - 1]) return -1;//if either of the last 2 numbers are 0, we will return -1
        // if (cnt == 0 && nums[nums.size() - 2] && nums[nums.size() - 1]) return 0;
        return cnt;//otherwise we can return the count 
    }
};
