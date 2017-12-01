#include <cstring>
#include <cstdio>
using namespace std;
const int up = 0;
const int down = 1;
const int left = 2;
const int right = 3;
int n, m;
int arr[15][15] = {};
bool success;
bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x <n && y < m && !arr[y][x];
}
void print(int* arr, int size) { 
    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void dfs(int x, int y, int* path, int step) {
    if (success) return;
    if (x == n-1 && y == m-1) {
        print(path, step);
        success = true;
        return;
    }
    if (valid(x, y-1)) {
        path[step] = up;
        arr[y-1][x]++;
        dfs(x, y-1, path, step + 1);
        arr[y-1][x]--;
    }
    if (valid(x, y+1)) {
        path[step] = down;
        arr[y+1][x]++;
        dfs(x, y+1, path ,step + 1);
        arr[y+1][x]--;
    }
    if (valid(x-1, y)) {
        path[step] = left;
        arr[y][x-1]++;
        dfs(x-1, y, path ,step + 1);
        arr[y][x-1]--;
    }
    if (valid(x +1, y)) {
        path[step] = right;
        arr[y][x+1]++;
        dfs(x+1, y, path, step + 1);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        success = false;
        scanf("%d%d", &m, &n);
        memset(arr, 0, 15 * 15 * sizeof(int));
        int path[100] = {};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%1d", &arr[i][j]);
            }
        }
        if (arr[0][0] == 1) {
            printf("no path\n");
            continue;
        }
        arr[0][0] = 1;
        dfs(0, 0, path, 0);
        if (!success) {
            printf("no path\n");
        }
    }
}
