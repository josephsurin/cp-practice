#include <iostream>
#include <cmath>

using namespace std;

int is_prime(int n) {
    if(n%2 == 0 && n > 2) {
        return 0;
    }
    for(int i = 3; i < (int)sqrt(n)+1; i+=2) {
        if(n%i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T, x, y, c;
    c = 0;
    cin >> T;
    while(T >= 3) {
        if(T == 4) {
            c += 1;
            break;
        }
        for(x = 3; x <= (int)T/2; x += 2) {
            y = T-x;
            if(is_prime(x) and is_prime(y)) {
                c += 1;
                T = y-x;
                break;
            }
        }
    }
    cout << c << endl;
    return 0;
}
