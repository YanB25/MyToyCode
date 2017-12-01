#include <stdio.h>
#include <memory.h>
char a[1005];
char b[1005];
int dp[1001][1001];
int main() {
    while (~scanf("%s%s", a + 1, b + 1)) {
        memset(dp, 0, 1005*1005);
        int i, j;
        for (i = 1;a[i]; i++) {
            for (j = 1;b[j]; j++) {
                if (a[i] == b[j]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                } else {
                    dp[i][j] = dp[i-1][j] > dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
                }
            }
        }
        printf("%d\n", dp[i-1][j-1]);
    }
    return 0;
}
        
