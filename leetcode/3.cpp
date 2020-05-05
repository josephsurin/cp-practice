/* longest substring without repeating characters
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /* iterate over the characters in s
         * map m holds (char, index)
         */
        unordered_map<char, int> m;
        int j = 0;
        int best = 0;
        for(int i = 0; i < s.length(); i++) {
            if(m.count(s[i])) {
                j = max(m[s[i]], j);
            }
            best = max(best, i - j + 1);
            m[s[i]] =  i + 1;
        }
        return best;
    }
};
