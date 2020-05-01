#include <stdio.h>

int main() {
    int S;
    scanf("%d", &S);
    while(S--) {
        int H;
        scanf("%d", &H);
        int curr = 0, best = 0;
        while(H--) {
            int p;
            scanf("%d", &p);
            curr += p;
            best = curr > best ? curr : best;
            if(curr <= 0) {
                curr = 0;
            }
        }
        printf("%d\n", best);
    }
}
