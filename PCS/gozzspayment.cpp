#include <ios>
#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int T;
	cin >> T;
	while(T--) {
		int X, a, b;
		cin >> X >> a >> b;
		string f = "NO";
		for(int i = 0; i <= a; ++i) {
			for(int j = 0; j <= b; ++j) {
				if(5*i + 7*j == X) {
					f = "YES";
					break;
				}
			}
		}
		cout << f << '\n';
	}

	return 0;
}