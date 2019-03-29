#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int i = 0; i < T; ++i) {
		double R, C;
		cin >> R >> C;
		cout << setprecision(7) << 3.1415926536*(R*R - (C*C)/4) << '\n';
	}
	return 0;
}