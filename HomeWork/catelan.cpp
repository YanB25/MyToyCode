#include <iostream>
using namespace std;
int main() {
    int arr[100];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= 50; ++i) {
        int sum = 0;
        for (int k = 0; k < i; ++k) {
            sum += arr[k]*arr[i-1-k];
        }
        arr[i] = sum;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << arr[n] << endl;
    }
}
