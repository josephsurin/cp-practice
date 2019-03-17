#include <iostream>
#include <string>
#include <vector>

using namespace std;

string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";

int dist(char, char);

int main() {
	int R, C;
	cin >> R >> C;
	cin.ignore();
	vector<string> origs;
	for(int i = 0; i < R; ++i) {
		string orig;
		getline(cin, orig);
		origs.push_back(orig);
	}
	for(int r = 0; r < R; ++r) {
		string orig, mod;
		orig = origs[r];
		getline(cin, mod);
		for(int c = 0; c < C; ++c) {
			if(c != 0) {
				cout << " ";
			}
			cout << dist(orig[c], mod[c]);
		}
		cout << endl;
	}
}

//dist to get from a to b
int dist(char a, char b) {
	int apos = characters.find(a);
	int bpos = characters.find(b);
	int d = bpos - apos;
	if(apos > bpos) {
		d += characters.length();
	}
	return d;
}