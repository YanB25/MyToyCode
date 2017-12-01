#include <cstdio>
using namespace std;
void hnt(int from, int end, int tmp, int n) {
    if (n == 1) {
        printf("move disk %d from peg %d to peg %d\n", n, from, end);
        return ;
    }
    hnt(from, tmp, end, n-1);
    printf("move disk %d from peg %d to peg %d\n", n, from, end);
    hnt(tmp, end, from, n-1);
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int m;
        scanf("%d", &m);
        hnt(1, 3, 2, m);
    }
}
