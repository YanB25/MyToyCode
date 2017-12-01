#include <iostream>
using namespace std;
void sort(int* arr, int beg, int end) {
    for (int i = beg; i < end - 1; ++i) {
        for (int j = i; j < end - 1; ++j) {
            if (arr[j + 1] < arr[j]) {
                swap(arr[j + 1], arr[j]);
            }
        }
    }
}

int main() {
    int arr[20];
    for (int i = 0; i < 20; ++i) arr[i] = 20 - 1;
    sort(arr, 0, 19);
    for (int i = 0; i < 20; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
