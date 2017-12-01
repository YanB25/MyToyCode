#include <iostream>
#include <algorithm>
using namespace std;
void sort(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] > arr[i]) {
                std::swap(arr[j], arr[i]);
            }
        }
    }
}

int main() {
    int arr[] = {5, 3, 4, 6, 7, 2, 1, 8, 9, 12, 43, 5, 1, 7, 9 };
    int size = sizeof(arr) / sizeof(int);
    sort(arr, size);
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
