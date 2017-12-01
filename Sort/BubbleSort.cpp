#include <iostream>
#include <algorithm>
using namespace std;
void sort(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main() {
    int arr[] = {1, 4, 2, 3, 7, 8,9,4,3,1,3,5,6,7,8,0,1,4,65,7,4};
    sort(arr, sizeof(arr)/sizeof(int));
    for (auto i : arr) cout << i << " ";
    cout <<endl;
}
