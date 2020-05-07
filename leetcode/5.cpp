/* longest palindromic substring
 * given a string s, find the longest palindromic substring in s
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 0) return s;
        int n = s.length();
        bool dp[n][n];        
        string ans = "";
        int best = 0;
        for(int j = 0; j < n; j++) {
            for(int i = 0; i <= j; i++) {
                bool b = s[i] == s[j];
                dp[i][j] = j > i + 2 ? dp[i+1][j-1] && b : b;
                if(dp[i][j] && j - i + 1 > best) {
                    best = j - i + 1;
                    ans = s.substr(i, j-i+1);
                }
            }
        }
        return ans;
    }
};
