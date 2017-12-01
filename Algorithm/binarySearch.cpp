#include <iostream>
using namespace std;
int binarySearchL(int* arr, int beg, int end, int tar) {
    if (beg == end) return arr[beg] == tar? beg : -1;
    int mid = (beg + end) / 2;
    if (arr[mid] < tar) {
        return binarySearchL(arr, mid + 1, end, tar);
    } else {
        return binarySearchL(arr, beg, mid, tar);
    }
}
int binarySearchR(int* arr, int beg, int end, int tar) {
    if (beg == end) return arr[beg] == tar ? beg : -1;
    int mid = (beg + end + 1) /2 ;
    if (arr[mid] <= tar) {
        return binarySearchR(arr, mid, end, tar);
    } else {
        return binarySearchR(arr, beg, mid - 1, tar);
    }
}
int main() {
    int arr[] = {1,1,1,1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,3,3,4,4,4,4,4,4,4};
    for (int i = 0; i < 7; ++i) {
        cout << "l " <<  i << " " << binarySearchL(arr, 0, sizeof(arr) / sizeof(int) - 1, i) << endl;
        cout << "r " <<  i << " " << binarySearchR(arr, 0, sizeof(arr) / sizeof(int) - 1, i) << endl;
    }
}
