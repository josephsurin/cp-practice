/* palindrome number
 * determine whether an integer is a palindrome
 * e.g. 121 yes, -121 no
 */

#include <bits/stdc++.h>

using namespace std;

int num_digits(int x) {
    if(x < 0) return 1;
    int d = 0;
    while(x > 0) {
        x /= 10;
        d += 1;
    }
    return d;
}

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;       
        int d = num_digits(x);
        int m = 10;
        int p = pow(10, d-1);
        for(int i = 0; i < d/2; i++) {
            if(x % 10 != (x / p) % 10) {
                return false;
            }
            x /= 10;
            p /= 100;
        }
        return true;
    }
};
