//1876. Substrings of Size Three with Distinct Characters - leetcode (easy) (acc : )
//https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/?envType=problem-list-v2&envId=sliding-window
/*
A string is good if there are no repeated characters.
Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.
Note that if there are multiple occurrences of the same substring, every occurrence should be counted.
A substring is a contiguous sequence of characters in a string.
*/
class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map <char, int> m;
        int n = s.size(), cnt = 0;
        for (int i = 0; i < 3; i++) {
            m[s[i]]++;
        }
        if (m.size() == 3) cnt++;
        for (int i = 3; i < n; i++) {
            // cout << s[i - 3] << " " << s[i] << endl;
            m[s[i - 3]]--;
            m[s[i]]++;
            int x = 0;
            for (auto i : m) {
                if (i.second == 1) x++;
            }
            if (x == 3) cnt++;
        }
        return cnt;
    }
};
