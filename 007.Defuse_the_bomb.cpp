//Defuse the bomb - leetcode (easy) (acc : 79%)
//https://leetcode.com/problems/defuse-the-bomb/description/
/*
You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.

To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

If k > 0, replace the ith number with the sum of the next k numbers.
If k < 0, replace the ith number with the sum of the previous k numbers.
If k == 0, replace the ith number with 0.
As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!
*/
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector <int> prefix(n);
        prefix[0] = code[0];
        for (int i = 1; i < code.size(); i++) {
            prefix[i] = prefix[i - 1] + code[i];
        }
        vector <int> ans(n);
        if (k == 0) {
            for (int i = 0; i < n; i++) ans[i] = 0;
            return ans;
        }
        else if (k > 0) {
            for (int i = 0; i < n; i++) {
                if (i < (n - k))
                ans[i] = prefix[i + k] - prefix[i];
                else
                ans[i] = prefix[n - 1] - prefix[i] + prefix[(i+k)%n]; 
            }
            return ans;
        }
        else {
            k *= -1;
            for (int i = 0; i < n; i++) {
                if (i > k) {
                    ans[i] = prefix[i - 1] - prefix[i - k - 1];
                }
                else if (i == k) ans[i] = prefix[i - 1];
                else {
                    ans[i] = (i==0 ? 0 : prefix[i - 1]) + prefix[n-1] - prefix[n - 1 - (k - i)];
                }
            }
        }
        return ans;
    }
};
