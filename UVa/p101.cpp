#include <iostream>
#include <algorithm>
#include <iterator>
#include <typeinfo>
#include <string>
#include <vector>

using namespace std;

void move_original(vector<vector<int> >&, int, int);
void move_all_original(vector<vector<int> >&, int);
void move_stack(vector<vector<int> >&, auto, int);
void move_onto(vector<vector<int> >&, int, int);
void move_over(vector<vector<int> >&, int, int);
void pile_onto(vector<vector<int> >&, int, int);
void pile_over(vector<vector<int> >&, int, int);

int main() {
	int n;
	cin >> n;
	string cmd1;
	string cmd2;
	int a,b;
	vector<vector<int>> bw {};
	for(int i = 0; i < n; ++i)
		bw.push_back({i});
	while(true) {
		cin >> cmd1;
		if(cmd1 == "quit") break;
		cin >> a >> cmd2 >> b;
		string cmd = cmd1+cmd2;
		if(cmd == "moveonto") move_onto(bw, a, b);
		if(cmd == "moveover") move_over(bw, a, b);
		if(cmd == "pileonto") pile_onto(bw, a, b);
		if(cmd == "pileover") pile_over(bw, a, b);
	}
	for(int i = 0; i < n; ++i) {
		cout << i << " :";
		for(auto s : bw[i])
			cout << " " << s;
		cout << endl;
	}
}

void move_onto(vector<vector<int> > &bw, int a, int b) {
	move_all_original(bw, a);
	move_all_original(bw, b);
	bw[b].push_back(a);
	bw[a].clear();
}

void move_over(vector<vector<int> > &bw, int a, int b) {
	move_all_original(bw, a);
	auto s = find_if(bw.begin(), bw.end(), [&](auto v) { return find(v.begin(), v.end(), b) != v.end(); });
	s[0].push_back(a);
	bw[a].clear();
}

void pile_onto(vector<vector<int> > &bw, int a, int b) {
	move_all_original(bw, b);
	auto s = find_if(bw.begin(), bw.end(), [&](auto v) { return find(v.begin(), v.end(), a) != v.end(); });
	move_stack(bw, s, b);
}

void pile_over(vector<vector<int> > &bw, int a, int b) {
	auto s = find_if(bw.begin(), bw.end(), [&](auto v) { return find(v.begin(), v.end(), b) != v.end(); });
	move_stack(bw, s, b); 
}

void move_stack(vector<vector<int> > &bw, auto s, int b) {
	while(s[0].size()) {
		bw[b].push_back(s[0][0]);
		s[0].erase(s[0].begin());
	}
}

void move_all_original(vector<vector<int> > &bw, int a) {
	for_each(bw[a].rbegin(), bw[a].rend(), [&bw, &a](int s) { move_original(bw, a, s); });
}

void move_original(vector<vector<int> > &bw, int a, int s) {
	bw[s].push_back(s);
	bw[a].erase(bw[a].end()-1);
}
