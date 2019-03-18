#include <iostream>
#include <vector>
#include <tuple>
#include <functional>
#include <algorithm>

using namespace std;

int find_optimal(int, int, int, vector<int>&, vector< tuple<int, int, int> >&);

int main() {
	int N, F, M;
	cin >> N >> F >> M;
	vector<int> ratings;
	for(int i = 0; i < N; ++i) {
		int r;
		cin >> r;
		ratings.push_back(r);
	}
	vector< tuple<int, int, int> > flights;
	for(int i = 0; i < F; ++i) {
		int d, a, m;
		cin >> d >> a >> m;
		flights.push_back(make_tuple(d, a, m));
	}
	cout << find_optimal(N, F, M, ratings, flights) << endl;
}

int find_optimal(int N, int F, int M, vector<int> &ratings, vector< tuple<int, int, int> > &flights) {
	function<int(int, int, int)> find_optimal_r;

	find_optimal_r = [&](int n, int ts, int current_rating) -> int {
		tuple<int, int, int> current_flight = flights[n];
		int current_airport = get<0>(current_flight);
		int dest_airport = get<1>(current_flight);
		int flight_duration = get<2>(current_flight);
		
		if(flight_duration > M) return 0;

		if(dest_airport == N) {
			if(ts + flight_duration > M) {
				return min(current_rating, ratings[current_airport-1]);
			} else {
				return current_rating;
			}
		}

		vector<int> next_f;
		for(int i = 0; i < F; ++i) {
			if(get<0>(flights[i]) == dest_airport) {
				next_f.push_back(i);
			}
		}

		int new_rating = current_rating < ratings[current_airport-1] ? current_rating : ratings[current_airport-1];
		vector<int> next_optimals;
		transform(next_f.begin(), next_f.end(), back_inserter(next_optimals), [new_rating, &find_optimal_r](int i) { return find_optimal_r(i, 0, new_rating); });

		if(ts + flight_duration <= M) { //bathroom break optional
			vector<int> next_optimals_nogo;
			transform(next_f.begin(), next_f.end(), back_inserter(next_optimals_nogo), [current_rating, ts, flight_duration, &find_optimal_r](int i) { return find_optimal_r(i, ts + flight_duration, current_rating); });
			next_optimals.insert(next_optimals.end(), next_optimals_nogo.begin(), next_optimals_nogo.end());
		}

		return *max_element(next_optimals.begin(), next_optimals.end());
	};

	vector<int> start_f;
	for(int i = 0; i < F; ++i) {
		if(get<0>(flights[i]) == 1) {
			if(get<2>(flights[i]) <= M) {
				start_f.push_back(i);
			}
		}
	}

	if(start_f.empty()) {
		return -1;
	}

	vector<int> next_optimals;
	transform(start_f.begin(), start_f.end(), back_inserter(next_optimals), [&find_optimal_r](int i) { return find_optimal_r(i, 0, 100); });
	return *max_element(next_optimals.begin(), next_optimals.end());
}