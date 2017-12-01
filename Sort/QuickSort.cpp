#include <iostream>
using namespace std;
void QuickSort(int* arr, int beg, int end) {
    if (beg >= end) return;
    int pivot = arr[end];
    int index = beg;
    for (int i = beg; i < end; ++i) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[index++]);
        }
    }
    swap(arr[index], arr[end]);
    QuickSort(arr, beg, index - 1);
    QuickSort(arr, index + 1, end);
}

int main() {
    int arr[] = {1, 5, 2 ,3, 7, 2, 4, 8};
    QuickSort(arr, 0, 7);
    for (auto i : arr) cout << i << " ";
    cout << endl;
}
