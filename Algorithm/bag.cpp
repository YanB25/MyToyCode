#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int item, contain;
    cin >> item >> contain;
    int heavy[100] = {};
    int value[100] = {};
    for (int i = 1; i < item; ++i) {
        cin >> heavy[i] >> value[i];
    }
    int arr[2][100] = {};
    for (int j = 1; j <= contain; ++j) {
        for (int i = 1; i <= item; ++i) {
            int index = i % 2;
            int other = !index;
            if (j >= heavy[i]) {
                arr[index][j] = max(arr[other][j], arr[other][j - heavy[i]] + value[i]);
            } else {
                arr[index][j] = arr[other][j];
            }
        }
    }
    int index = item % 2;
    cout << arr[index][contain] << endl;
}
