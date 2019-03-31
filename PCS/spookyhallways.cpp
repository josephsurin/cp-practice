#include <ios>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector< vector<int > > edges;
		while(M--) {
			int u, v;
			cin >> u >> v;
			edges.push_back({ u, v });
		}
		map<int, int> degrees;
		for(auto &e: edges) {
			for(int v = 0; v < 2; ++v) {
				if(degrees.count(e.at(v))) {
					degrees[e[v]] += 1;
				} else {
					degrees[e[v]] = 1;
				}
			}
		}
		int num_odd = count_if(degrees.begin(), degrees.end(), [](auto d) { return d.second & 1; });
		cout << num_odd/2 << '\n';
	}

	return 0;
}