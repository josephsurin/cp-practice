#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int S;
    cin >> S;
    for(int i = 0; i < S; ++i) {
        int H;
        cin >> H;
        int maxp = 0;
        int sum = 0;
        while(H--) {
            int p;
            cin >> p;
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