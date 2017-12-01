#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
struct Stu {
    int arr[7];
    Stu(int* arr_) {
        int min = arr_[0]; int minIndex = 0;
        for (int i = 1; i < 7; ++i) {
            if (arr_[i] < min) {
                min = arr_[i];
                minIndex = i;
            }
        }
        for (int i = 0; i < 7; ++i) {
            arr[i] = arr_[(i + minIndex) % 7];
        }
    }
    bool operator<(const Stu& rhs) const {
        for (int i = 0; i < 7; ++i) {
            if (arr[i] != rhs.arr[i])
                return arr[i] < rhs.arr[i];
        }
        return false;
    }
};
int main() {
    multimap<Stu, int> datas;
    int id;
    while (~scanf("%d", &id)) {
        int arr[7];
        for (int i = 0; i < 7; ++i) scanf("%d", &arr[i]);
        datas.insert(pair<Stu, int>(Stu(arr), id));
    }
    for (auto it = datas.begin(); it != datas.end(); ) {
        auto range = datas.equal_range((*it).first);
        auto it2 = range.first;
        if (++it2 == range.second) {
            it++;
            continue;
        }
        for (it = range.first; it != range.second; ++it) {
            cout << (*it).second << " ";
        }
        cout << endl;
    }
    return 0;
}


