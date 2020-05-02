/* two sum II - input array is sorted
 * two sum with input array sorted
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> m; 
        for(int i = 0; i < numbers.size(); i++) {
            int n = numbers[i];
            if(m.count(n)) {
                vector<int> ans;
                ans.emplace_back(m[n]);
                ans.emplace_back(i+1);
                return ans;
            }
            m[target - n] = i+1;
        }
    return {};
    }
};
