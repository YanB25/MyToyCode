#include <iostream>
using namespace std;
int arr[100] = {};
void print(int* arr, int n) {
    cout << arr[0];
    for (int i = 1; i < n ;++i) {
        cout << "+" << arr[i];
    }
    cout << endl;
}
void dfs(int m, int last, int step) {
    if (m < 0)return;
    if (m == 0) {
        print(arr, step);
    }
    for (int i = last; i > 0; --i) {
        arr[step] = i;
        dfs(m - i, i, step + 1);
        arr[step] = 0;
    }
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        dfs(m, m, 0);
    }
}
