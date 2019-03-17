#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<vector<int>> bins {}; // { {G1, B1, C1}, {G2, B2, C2}, {G3, B3, C3} }
	int g1,b1,c1,g2,b2,c2,g3,b3,c3;
	cin >> g1 >> b2 >> c1 >> g2 >> b2 >> c2 >> g3 >> b3 >> c3;
	bins.push_back({g1, b1, c1});
	bins.push_back({g2, b2, c2});
	bins.push_back({g3, b3, c3});
	vector<int> totals {g1+g2+g3, b1+b2+b3, c1+c2+c3}; // { TG, TB, TC }
	max_element(bins.begin(), bins.end());
	
}