#include <iostream>
#include <ios>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int T;
	cin >> T;
	while(T--) {
		int N, W;
		cin >> N >> W;
		vector<int> weights;
		while(N--) {
			int a;
			cin >> a;
			weights.push_back(a);
		}
		int max = 0;
		for(int i = 0; i < N; ++i) {
			int running = weights[i];
			for(int j = i+1; j < N; ++j) {
				running += weights[j];
				if(running == W && (j-i) > max) {
					max = j-i;
				}
			}
		}
		cout << max << '\n';
	}

	return 0;
}