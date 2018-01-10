#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;
void print(const vector<int>& arr) {
    for (auto item : arr) {
        cout << item << " ";
    }
    cout << endl;
}
void sort(vector<int>& arr, int beg, int end) {
    for (int i = 0; i <= end; ++i) {
        int k = i;
        bool action = false;
        while (k-1 >= 0 && arr[k] < arr[k-1]) {
            action = true;
            std::swap(arr[k], arr[k-1]);
            k--;
        }
        if (action) {
            cnt++;
            action = false;
        }
    }
#ifdef DEBUG
    print(arr);
#endif
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        cnt = 0;
        int n;
        cin >> n;
        vector<int> arr(n);        
        for (int i = 0; i < n; ++i) {
            int tmp; cin >> tmp;
            arr[i] = tmp;
        }
        sort(arr, 0, arr.size()-1);
        cout << cnt*5 << endl;
    }
}
