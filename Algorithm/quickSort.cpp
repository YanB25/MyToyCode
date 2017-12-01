#include <iostream>
using namespace std;
void swap(int& lhs, int& rhs) {
    int tmp = lhs;
    lhs = rhs;
    rhs =tmp;
}
void quickSort(int* arr, int beg, int end) {
    if (beg >= end) return;
    int pivot = arr[end];
    int index = beg;
    for (int i = beg; i <= end; ++i) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[index++]);
        }
    }
    swap(arr[index], arr[end]);
    quickSort(arr, beg, index - 1);
    quickSort(arr, index + 1, end);
}
int main() {
    int arr[80];
    for (int i = 0; i < 80; ++i) {
        arr[i] = 40 - i;
    }
    quickSort(arr, 0, 79);
    for (int i = 0; i < 80; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
