#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <typeinfo>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector< vector<int> > edges;
	for(int i = 0; i < N - 1; ++i) {
		int a,b;
		cin >> a >> b;
		edges.push_back({ a, b });
	}
	map<int, int> connections;
	for(auto &e : edges) {
		for(int v = 0; v < 2; ++v) {
			if(connections.count(e.at(v))) {
				connections[e[v]] += 1;
			} else {
				connections[e[v]] = 1;
			}	
		}
	}
	int num_leaves = count_if(connections.begin(), connections.end(), [](auto d) { return d.second == 1; });
	cout << (num_leaves+1)/2 << '\n';
}