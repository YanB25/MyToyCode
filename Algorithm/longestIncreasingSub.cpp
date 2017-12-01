#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int maxNum = 0;
    cin >> n;
    int arr[100] = {};
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int num[100] = {};
    num[0] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] >= arr[j]) {
                num[i] = max(num[i], num[j] + 1);
                maxNum = max(maxNum, num[i]);
            }
        }
    }
    cout << maxNum << endl;
    return 0;
}
