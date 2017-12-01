#include <cstring>
#include <cstdio>
void print(int table[1005][1005], int m, int n) {
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}
int main() {
    char a1[1005];
    char a2[1005];
    int table[1005][1005];
    while (~scanf("%s %s", a1 + 1, a2 + 1)) {
        int m = strlen(a1 + 1);
        int n = strlen(a2 + 1);
        for (int i = 0; i <= m; ++i) table[i][0] = 0;
        for (int j = 0; j <= n; ++j) table[0][j] = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a1[i] == a2[j]) {
                    table[i][j] = table[i-1][j-1] + 1;
                } else {
                    table[i][j] = table[i-1][j] > table[i][j-1] ? table[i-1][j] : table[i][j-1];
                }
            }
        }
        //print(table, m, n);
        printf("%d\n", table[m][n]);
    }
    return 0;
}



