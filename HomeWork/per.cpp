#include <iostream>
#include <algorithm>
using namespace std;
void print( int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] + 1 << " ";
    }
    cout << endl;
}
void per(int* arr, int n) {
    while (true) {
        int index = n-1;
        while (index > 0 && arr[index - 1] > arr[index]) index--;
        if (index == 0) return;
        int sw = arr[index - 1];
        for (int i = n - 1; i >= index; --i) {
            if (arr[i] > sw) {
                swap(arr[i], arr[index - 1]);
                break;
            }
        }
        sort(arr + index, arr + n);
        print(arr, n);
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        int arr[15];
        for (int i = 0; i < m; ++i) arr[i] = i;
        print(arr, m);
        per(arr, m);
    }
    return 0;
}
