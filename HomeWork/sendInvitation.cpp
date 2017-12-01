#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        int num;
        cin >> num;
        int max = num;
        for (int i = 1; i < m; ++i) {
            cin >> num;
            max = num > max ? num : max;
        }
        int cnt = 0;
        cin >> num;
        for (int i = 1; i < n; ++i) {
            cin >> num;
            if (num <= max) cnt++;
        }
        printf("%d\n", cnt * 50);
    }
}

