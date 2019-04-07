#include <ios>
#include <iostream>
#include <cmath>

#define MAX_N 1000001 

using namespace std;

int min_pf[MAX_N] = {0, 1};

void gen_min_pf() {
	for(int i = 2; i < MAX_N; i+=2) {
		min_pf[i] = 2;
		min_pf[i+1] = i+1;
	}
	for(int i = 3; i * i < MAX_N; i+=2) {
		if(min_pf[i] == i) {
			for(int j = i * i; j < MAX_N; j += i) {
				if(min_pf[j] == j)
					min_pf[j] = i;
			}
		}
	}
}

int numfacts(int N) {
	int j = N;
	int num = 1;
	while(j != 1) {
		int p = 0;
		int f = min_pf[j];
		while(j%f == 0) {
			j /= f;
			++p;
		}
		num *= (1+p);
	}
	return num;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	gen_min_pf();
	int Q;
	cin >> Q;
	while(Q--) {
		int N;
		cin >> N;
		cout << numfacts(N) << '\n';
	}

	return 0;
}