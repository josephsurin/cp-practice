#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int bs_l(vector<int> &v, int x) {
	int l = 0;
	int r = v.size();
	while(l < r) {
		int m = floor((l+r)/2);
		if(v[m] < x) {
			l = m + 1;
		} else {
			r = m;
		}
	}
	return l;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, Q;
	cin >> N >> Q;
	vector<int> b;
	while(N--) {
		int h;
		cin >> h;
		b.push_back(h);
	}
	sort(b.begin(), b.end());
	while(Q--) {
		int A, B;
		cin >> A >> B;
		int A_L = bs_l(b, A);
		int B_L = bs_l(b, B);
		if((int)b.size() > B_L && b[B_L] == B) {
			B_L += 1;
		}
		cout << B_L - A_L << endl;
	}
	return 0;
}