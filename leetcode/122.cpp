/* best time to buy and sell stock II
 * given an array prices[] for which the ith element is the price of a given stock on day i, find the maximum profit
 * you can buy on one day and sell on a later day many times, but cannot buy stocks twice in a row
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = 0;       
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i-1]) {
                m += prices[i] - prices[i-1];
            }
        }
        return m;
    }
};
