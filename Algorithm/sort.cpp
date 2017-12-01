#include <iostream>
using namespace std;
void sort(int* arr, int beg, int end) {
    if (beg >= end) return;
    int pivot = arr[end];
    int index = beg;
    for (int i = beg; i < end; ++i) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[index++]);
        }
    }
    swap(arr[index], arr[end]);
    sort(arr, beg, index - 1);
    sort(arr, index + 1, end);
}

int main() {
    int arr[20];
    for (int i = 0; i < 20; ++i) arr[i] = 30 - i;
    sort(arr, 0, 19);
    for (int i = 0; i < 20; ++i) 
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
