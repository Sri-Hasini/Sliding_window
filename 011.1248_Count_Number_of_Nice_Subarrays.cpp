//1248. Count Number of Nice Subarrays - leetcode (medium) (acc : 72%)
//https://leetcode.com/problems/count-number-of-nice-subarrays/description/?envType=problem-list-v2&envId=sliding-window
/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.
*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int odd = 0;
        int left = 0, right = 0, cnt = 0;
        for (int right = 0; right < nums.size(); right++) {
            //used & because num & 1 will return 1 if the num is odd, 0 otherwise
            if (nums[right] & 1) odd++;//incrementing if it is odd number
            int y = left;//storing the left value before the process when the odd count equals k
            if (odd == k) {
                while (odd == k) {
                    if (nums[left] & 1) {//update odd, if odd is found at left part inorder to shrink
                        odd--;
                    }
                    left++;
                }
                int nxt = nums.size();// if no odd is found, it will have the length 
                //finding for the next odd value
                for (int i = right + 1; i < nums.size(); i++) {
                    if (nums[i] & 1) {
                        nxt = i;//if found, we can break
                        break;
                    }
                }
                //adding the left part before the 1st odd number of the sastisfied subarray 
                //add extra 1, for the satisfied part
                //instead of writing cnt += (left - y - 1) + 1, we can write cnt += (left - y)
                //adding the remaining elements to the right until the next odd
                //also adding the product of the above 2 to the count
                cnt += (left - y) + (nxt - (right + 1)) + (left - y - 1) * (nxt - (right + 1));
            }
        }
        return cnt;
    }
};
