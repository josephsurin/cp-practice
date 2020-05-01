/*
 * lucky numbers in a matrix
 * 
 * given a m*n matrix of distinct numbers, return all lucky numbers in the matrix (in any order)
 * a lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> possible1;
        for(auto r : matrix) {
            possible1.emplace_back(*min_element(r.begin(), r.end()));
        }
        vector<int> possible2;
        for(int i = 0; i < matrix[0].size(); i++) {
            int c = matrix[0][i];
            for(int j = 1; j < matrix.size(); j++) {
                c = max(c, matrix[j][i]);
            }
            possible2.emplace_back(c);
        }
        sort(possible1.begin(), possible1.end());
        sort(possible2.begin(), possible2.end());
        vector<int> possible;
        set_intersection(possible1.begin(), possible1.end(), possible2.begin(), possible2.end(), back_inserter(possible));
        return possible;
    }
};
