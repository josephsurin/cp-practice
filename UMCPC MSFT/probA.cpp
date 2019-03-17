#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
	int N;
	string s_flightnum, arrival_time;
	cin >> N >> s_flightnum >> arrival_time;
	vector< tuple<int, string> > suspects;
	for(int i = 0; i < N; ++i) {
		string name, flightnum, finish_time;
		cin >> name >> flightnum >> finish_time;
		if(flightnum == s_flightnum) {
			int ath = stoi(arrival_time.substr(0, 2));
			int atm = stoi(arrival_time.substr(3, 5));
			int fth = stoi(finish_time.substr(0,2));
			int ftm = stoi(finish_time.substr(3, 5));
			int t = (fth - ath) * 60 + (ftm-atm);
			suspects.push_back(make_tuple(t, name));
		}
	}
	
	sort(suspects.begin(), suspects.end(), [](tuple<int, string> a, tuple<int, string>b) { return get<0>(a) > get<0>(b); });
	int counter = 0;
	for(auto &s : suspects) {
		cout << get<1>(s) << " " << to_string(get<0>(s)) << endl;
		++counter;
		if(counter == 3) {
			return 0;
		}
	}

	return 0;
}