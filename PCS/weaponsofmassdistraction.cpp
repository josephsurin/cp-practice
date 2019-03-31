#include <ios>
#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int N;
	cin >> N;
	vector< tuple<int, int, int> > bombs;
	int last = N-1;
	while(N--) {
		int r, i, j;
		cin >> r >> i >> j;
		bombs.push_back({ r, i, j });
	}
	string ans = "no collision\n";
	for(int i = 0; i <= last; ++i) {
		for(int j = i+1; j <= last; ++j) {
			tuple<int, int, int> a = bombs[i];
			tuple<int, int, int> b = bombs[j];
			int A_x, A_y, A_r, B_x, B_y, B_r;
			A_r = get<0>(a);
			A_x = get<1>(a);
			A_y = get<2>(a);
			B_r = get<0>(b);
			B_x = get<1>(b);
			B_y = get<2>(b);
 			double modAB = sqrt(pow(abs(B_x - A_x), 2) + pow(abs(B_y - A_y), 2));
			if(modAB <= A_r + B_r) { //collision
				if(i != last && j != last) {
					cout << "safely stopped collision\n";
					return 0;
				} else {
					ans = "collision\n";
				}
			}
		}
	}
	cout << ans;

	return 0;
}