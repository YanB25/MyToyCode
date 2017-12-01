#include <iostream>
#include <algorithm>
using namespace std;
void sort(int* arr, int beg, int end) {
    if (beg >= end) return;
    int mid = (beg + end) / 2;
    int b1 = beg, e1 = mid;
    int b2 = mid + 1, e2 = end;
    sort(arr, b1, e1);
    sort(arr, b2, e2);
    int* tmp = new int[end - beg + 5];
    int index = 0;
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
}
int main() {
    int arr[] = {2 ,4 ,5 ,6 ,7 ,8,7,6,1,2,34,9,8,6,5,4,3};
    int size = sizeof(arr) / sizeof(int);
    sort(arr, 0, size- 1);
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
