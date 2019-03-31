#include <ios>
#include <iostream>
#include <string>
#include <vector>

#define MAX(a,b) ((a)>(b) ? (a) : (b))

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		int n = s.size();
		vector< vector<int> > L(n);
		for(int i = 0; i < n; ++i) {
			L[i].reserve(n);
			L[i][i] = 1;
		}
		for(int sl = 2; sl <= n; ++sl) { //sl is length of subsequence being considered
			for(int a = 0; a <= n - sl; ++a) {
				int b = a + sl - 1;
				if(s[a] == s[b]) {
					if(sl == 2) L[a][b] = 2;
					else L[a][b] = L[a+1][b-1] + 2;
				} else {
					L[a][b] = MAX(L[a][b-1], L[a+1][b]);
				}

			}
		}
		cout << n - L[0][n-1] << '\n';

	}

	return 0;
}