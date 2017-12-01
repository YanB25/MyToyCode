#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Student {
    int id;
    int g1;
    int g2;
    int g3;
    int sum;
    Student(int id_, int g1_, int g2_, int g3_) {
        id = id_;
        g1 = g1_;
        g2 = g2_;
        g3 = g3_;
        sum = g1 + g2 + g3;
    }
    bool operator<(const Student& rhs) const {
        if (sum != rhs.sum) {
            return sum > rhs.sum;
        }
        if (g1 != rhs.g1) {
            return g1 > rhs.g1;
        }
        return id < rhs.id;
    }
};

int main() {
    int n;
    bool first = true;
    while (~scanf("%d", &n)) {
        if (first) {
            first = false;
        } else {
            printf("\n");
        }
        vector<Student> vec;
        for (int i = 0 ; i < n; ++i) {
            int g1, g2, g3;
            scanf("%d%d%d", &g1, &g2, &g3);
            vec.emplace_back(i + 1, g1, g2, g3);
        }
        sort(vec.begin(), vec.end());
        for (int i = 0; i < 5; ++i) {
            printf("%d %d\n", vec[i].id, vec[i].sum);
        }
    }
}



