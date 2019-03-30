#include <iostream>
#include <vector>

using namespace std;

int main() {
    int S;
    cin >> S;
    for(int i = 0; i < S; ++i) {
        int H;
        cin >> H;
        vector<int> P;
        for(int j = 0; j < H; ++j) {
            int p;
            cin >> p;
            P.push_back(p);
        }
        int maxp = 0;
        int sum = 0;
        for( auto &p : P) {
            if(p < 0) {
                if(sum > maxp) {
                    maxp = sum;
                }
            }
            if(sum + p < 0) {
                sum = 0;
            } else {
                sum += p;
            }
        }
        maxp = maxp > sum ? maxp : sum;
        cout << maxp << '\n';
    }
    return 0;
}