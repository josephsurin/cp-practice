#include <ios>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int X, d;
		cin >> X >> d;
		if(d > 1 && X >= (int)pow(10, d)) {
			cout << -1 << '\n';
		} else {
			int m = (ceil(pow(10,d)/X) - 1) * X;
			cout << m << '\n';
		}
	}
	return 0;
}