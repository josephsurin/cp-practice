#include <ios>
#include <iostream>
#include <cmath>

using namespace std;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

bool isprime(int N) {
	if(N == 1) return false;
	if(N == 2) return true;
	for(int i = 2; i * i <= N; ++i) {
		if(N%i == 0) return false;
	}
	return true;
}

int numfacts(int N) {
	int n = N;
	int num = 1;
	for(auto &p : primes) {
		if(p*p*p > N) break;
		int c = 1;
		while(n%p == 0) {
			n /= p;
			++c;
		}
		num *= c+1;
	}
	if(isprime(N)) return num*2;
	float sN = sqrt(N);
	if((int)sN == sN && isprime(sN)) return num*3;
	if(N != 1) return num*4;
	return num;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int Q;
	cin >> Q;
	while(Q--) {
		int N;
		cin >> N;
		cout << numfacts(N) << '\n';
	}

	return 0;
}