/* grumpy bookstore owner
 * maximise the value of sum(customers[i] for grumpy[i] == 0) allowing grumpy[i] = 0 for X consectuive i values
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int c = 0;
        for(int i = 0; i < X; i++) {
            c += customers[i];
        }
        for(int i = X; i < grumpy.size(); i++) {
            if(grumpy[i] == 0) {
                c += customers[i];
            }
        }
        int best = c;
        for(int i = 0; i < grumpy.size() - X; i++) {
            if(grumpy[i] == 1) {
                c -= customers[i]; 
            }
            if(grumpy[X+i] == 1) {
                c += customers[i+X];
            }
            best = max(c, best);
        }
        return best;
    }
};
