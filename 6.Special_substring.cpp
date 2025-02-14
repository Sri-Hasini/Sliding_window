//Special Substring - codechef (1400)
//https://www.codechef.com/practice/course/two-pointers/SLIDINGWINDO/problems/SLDW0104
/*
Chef gave you a string S of size N which contains only lowercase English letters and asked you to find the length of the longest substring of the string which satisfies the following condition:
Each character β should appear at most f(β) times.
Here f(β) denotes the index of the character β in the alphabet series. For example f( ′a′) = 1, f( ′b′ ) = 2 and so on.
Note: A substring of a string is a contiguous subsequence of that string.
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int left = 0, maxi = 0;
        vector <int> freq(26, 0);
        //taken only 26, as they have mentioned that the string have only lowercase
        for (int right = 0; right < n; right++) {
            freq[s[right] - 'a']++;
            while (freq[s[right] - 'a'] > (s[right] - 'a' + 1)) {
                freq[s[left] - 'a']--;
                left++;
            }
            //update the maximum length of the special substring
            maxi = max(maxi, right - left + 1);
        }
        cout << maxi << endl;
    }
}
