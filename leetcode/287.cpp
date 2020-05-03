/* find the duplicate number
 * given an array containing n+1 integers where each integer is between 1 and n inclusive, find the duplicate number
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto n : nums) {
            if(m.count(n) > 0) {
                return n;
            }
            m[n]++;
        }
    return -1;
    }
};
