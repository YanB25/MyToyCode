#include <iostream>
using namespace std;
void hnt(int n, char from, char to, char tmp) {
    if (n == 0) return;
    hnt(n-1, from, tmp, to);
    printf("%d from %c to %c\n", n, from, to);
    hnt(n-1, tmp, to, from);
}

int main() {
    int n;
    cin >> n;
    int arr[20] = {};
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 3;
    for (int i = 3; i < 20; ++i) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout << arr[n]<<endl;
    hnt(n, 'A', 'C', 'B');
}
