/* string to integer (atoi)
 * implement atoi
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long ans = 0;
        int i = 0;
        int sign = 1;
        while(str[i] == ' ') i++;
        if(i > str.length()) return 0;
        if(str[i] == '-') sign = -1;
        i += str[i] == '+' || str[i] == '-';
        while(i < str.length() && isdigit(str[i])) {
            ans = 10 * ans + (str[i] - '0');
            if(ans > INT_MAX) return sign == 1 ? INT_MAX : INT_MIN;
            i++;
        }
        return sign * ans;
    }
};
