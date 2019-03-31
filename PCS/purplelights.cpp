#include <ios>
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int sums[65541] = {0};
		int r = 1;
		int N = n;
		int l = 1<<n;
		while(N--) {
			int a, b;
			cin >> a >> b;
			int s = l / (1<<r);
			int c = 1<<(r-1);
			for(int j = 0; j < c; ++j) {
				for(int i = 0; i < s; ++i) {
					sums[2*s*j + i] += a;
				}
				for(int i = s; i < 2*s; ++i) {
					sums[2*s*j + i] -= b;
				}
			}
			++r;
		}
		int mindiff = abs(sums[0]);
		for(int i = 0; i < l; ++i) {
			if(abs(sums[i]) < mindiff) {
				mindiff = abs(sums[i]);
			}
		}
		cout << mindiff << '\n';
	}

	return 0;
}