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
	int N, Q;
	cin >> N >> Q;
	vector<int> b;
	for(int i = 0; i < N; ++i) {
		int h;
		cin >> h;
		b.push_back(h);
	}
	sort(b.begin(), b.end());
	for(int i = 0; i < Q; ++i) {
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