#include <iostream>
using namespace std;

void sort(int* arr, int beg, int end) {
    if (beg >= end) return;
    int mid = (beg + end) / 2;
    int b1 = beg; int e1 = mid;
    int b2 = mid + 1; int e2 = end;
    int index = 0;
    int* tmp = new int[end - beg + 1];
    sort(arr, b1, e1);
    sort(arr, b2, e2);
    while (b1 <= e1 && b2 <= e2) {
       if (arr[b1] <= arr[b2]) {
           tmp[index++] = arr[b1++];
       } else {
           tmp[index++] = arr[b2++];
       }
    }
    while (b1 <= e1) tmp[index++] = arr[b1++];
    while (b2 <= e2) tmp[index++] = arr[b2++];
    for (int i = beg; i <= end; ++i) arr[i] = tmp[i - beg];
    delete[] tmp;
}

void print(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int arr[] = {1, 5, 3, 6,7,8,9,4,3,2,4,5,6,75,4,23,1,3,5,6,8,89,5,4,2,2,4,5,7,8};
    int size = sizeof(arr) / sizeof(int);
    sort(arr, 0, size-1);
    print(arr, size);
}
