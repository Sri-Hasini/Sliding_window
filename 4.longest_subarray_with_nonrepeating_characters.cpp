//Longest subarray with non repeating characters - leetcode (medium) (acc: 36%)
//https://leetcode.com/problems/longest-substring-without-repeating-characters/
/*
Given a string s, find the length of the longest substring without repeating characters.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, maxi = 0;
        map <char,int> m;
        while (right < s.size()) {
            while (m[s[right]] > 0 && right < s.size()){
                m[s[left]]--;
                left++;
            } 
            m[s[right]]++;
            maxi = max(maxi, right - left + 1);
            right++;
        }
        return maxi;
    }
};
