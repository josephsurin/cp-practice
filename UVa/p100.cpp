#include <iostream>

int getCycleLength(int);
int getMaxCycleLength(int, int);

int main() {
	int i, j;
	while(std::cin >> i >> j) {
		int ml = (j > i) ? getMaxCycleLength(i, j) : getMaxCycleLength(j, i);
		std::cout << i << " " << j << " " << ml << std::endl; 
	}
}

int getMaxCycleLength(int i, int j) {
	int max = 0;
	for(; i <= j; ++i) {
		int cL = getCycleLength(i);
		if(cL > max) max = cL;
	}
	return max;
}

int getCycleLength(int n) {
	int count = 1;
	while(n > 1) {
		if(n%2) n = 3*n+1;
		else n /= 2;
		++count;
	}
	return count;
}