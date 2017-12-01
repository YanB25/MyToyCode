#include <iostream>
#include <algorithm>
using namespace std;
void sort(int* arr, int beg, int end) {
    if (beg >= end) return;
    int pivot = arr[end];
    int index = beg;
    for (int i = beg; i <= end; ++i) {
        if (arr[i] < pivot) {
            std::swap(arr[i], arr[index++]);
        }
    }
    swap(arr[index], arr[end]);
    sort(arr, beg, index - 1);
    sort(arr, index + 1, end);
}
int main() {
    int arr[] = {1, 2, 6, 5, 3 ,4 ,8 ,9, 1, 2, 4, 6, 1, 7, 9, 3, 6};
    int size = sizeof(arr) / sizeof(int);
    sort(arr, 0, size - 1);
    for (int i = 0 ; i< size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

