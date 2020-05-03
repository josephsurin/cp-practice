/* contains duplicate
 * given an array of integers, find if the array contains any duplicates
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;       
        for(auto n : nums) {
            if(m.count(n) > 0) {
                return true;
            }
            m[n] += 1;
        }
        return false;
    }
};
