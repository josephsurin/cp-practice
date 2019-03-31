#include <ios>
#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int T;
	cin >> T;
	cin.ignore();
	while(T--) {
		string p;
		getline(cin, p);
		bool palindrome = true;
		int s = 0;
		int e = p.size();
		while(palindrome && s < e) {
			if(isalpha(p[s]) && isalpha(p[e-1])) {
				int S = p[s] - 0;
				int E = p[e-1] - 0;
				if(S != E && abs(S - E) != 32) {
					palindrome = false;
				} else {
					++s;
					--e;
				}
			} else {
				if(!isalpha(p[s])) {
					++s;
				}
				if(!isalpha(p[e-1])) {
					--e;
				}
			}

		}
		string res = palindrome ? "True" : "False";
		cout << res << '\n';
	}

	return 0;
}