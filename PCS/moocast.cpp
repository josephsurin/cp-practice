#include <ios>
#include <iostream>
#include <tuple>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int N;
	cin >> N;
	tuple<int, int, int> cows[205];
	for(int i = 0; i < N; ++i) {
		int x, y, p;
		cin >> x >> y >> p;
		cows[i] = {x, y, p};
	}
	map<int, set<int>> neighbours;
	for(int i = 0; i < N; ++i) {
		int a_x, a_y, a_r;
		a_x = get<0>(cows[i]);
		a_y = get<1>(cows[i]);
		a_r = get<2>(cows[i]);
		for(int j = i+1; j < N; ++j) {
			int b_x, b_y, b_r;
			b_x = get<0>(cows[j]);
			b_y = get<1>(cows[j]);
			b_r = get<2>(cows[j]);
			int modab = ((b_x-a_x)*(b_x-a_x) + (b_y-a_y)*(b_y-a_y));
			if(modab <= a_r*a_r)
				neighbours[i].insert(j);
			if(modab <= b_r*b_r)
				neighbours[j].insert(i);
		}
	}
	int maxreach = 0;
	for(auto &i : neighbours) {
		queue<int> tovisit;
		set<int> visited = {};
		tovisit.push(i.first);
		while(!tovisit.empty()) {
			int cv = tovisit.front();
			tovisit.pop();
			visited.insert(cv);
			for(auto &n : neighbours[cv]) {
				if(find(visited.begin(), visited.end(), n) == visited.end())
					tovisit.push(n);
			}
		}
		if(visited.size() > maxreach)
			maxreach = visited.size();
	}

	cout << maxreach;

	return 0;
}