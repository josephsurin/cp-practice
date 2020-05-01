/* image smoother
 * given a 2d integer matrix M representing the gray scale of an image, make the gray scale of each cell the average gray scale (integer round down) of all surrounding 8 cells and itself (or all surrounding cells for edge and corner cells)
 */

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> get_neighbours(int y, int x, int m, int n) {
    vector<pair<int, int>> neighbours = {{y-1,x-1}, {y-1,x},{y-1,x+1},{y,x-1},{y,x},{y,x+1},{y+1,x-1},{y+1,x},{y+1,x+1}};
    neighbours.erase(remove_if(neighbours.begin(), neighbours.end(), [m, n](pair<int, int> p) {
        return (p.first < 0 || p.first >= m || p.second < 0 || p.second >= n);
    }), neighbours.end());
    return neighbours;
}

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> smooth;
        int m = M.size();
        int n = M[0].size();
        for(int y = 0; y < m; y++) {
            vector<int> row;
            for(int x = 0; x < n; x++) {
                vector<pair<int, int>> neighbours = get_neighbours(y, x, m, n);
                int avg = 0;
                for(auto nb: neighbours) {
                    avg += M[nb.first][nb.second];
                }
                row.emplace_back(avg/neighbours.size());
            }
            smooth.emplace_back(row);
        }
        return smooth;
    }
};

int main() {
    vector<vector<int>> M = {{1,1,1},{1,0,1},{1,1,1}};
    Solution* s = new Solution();
    vector<vector<int>> smooth = s->imageSmoother(M);
    for(auto r : smooth) {
        for(auto x: r) {
            cout << x << "  ";
        }
        cout << endl;
    }
}
