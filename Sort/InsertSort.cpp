#include <iostream>
using namespace std;
void Sort(int* arr, int size) {
    arr[size + 5] = 2;
    for (int i = 0; i < size; ++i) {
        int tmp = arr[i];
        int index = i;
        while (index-1 >= 0 && tmp < arr[index - 1]) {
            arr[index] = arr[index -1];
            index--;
        }
        arr[index] = tmp;
    }
}
int main() {
    int arr[] = {5, 4, 2, 7, 9, 1, 3, 2, 1, 8, 0, 8, 6, 4, 3, 2, 1, 6, 7, 4, 2, 1, 0, 9, 8, 7, 4 ,7};
    int size = sizeof(arr)/ sizeof(int);
    Sort(arr,size);
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
