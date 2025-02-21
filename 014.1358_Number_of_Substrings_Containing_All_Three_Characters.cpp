//1358. Number of Substrings Containing All Three Characters - leetcode (acc : 68%) (medium)
//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/?envType=problem-list-v2&envId=sliding-window
/*
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.
*/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0, j = 0, cnt = 0;
        unordered_map<char, int> mp;//taken an unodered_map for storing the frequencies
        while (j < n) {
            mp[s[j]]++;//extend window by adding values to it
            while (mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1) {//if they all are greater than or equal to 1, then enter loop until any value becomes 0
                cnt += n - j;
                mp[s[i]]--;//shrinking window
                i++;
            }
            j++;
        }
        return cnt;
    }
};
