#include <vector>
#include <iostream>
using namespace std;
class disjointSet {
public:
    disjointSet(int size);
    int getID(int i);
    int Prev(int i) const;
    int size() const;
    bool isLinked(int lhs, int rhs);
    void link(int lhs, int rhs);
private:
    vector<int> rank;
    vector<int> prev;
    int size_;
};
int disjointSet::Prev(int i) const { return prev[i]; }
disjointSet::disjointSet(int size) : size_(size) {
    rank.resize(size);
    prev.resize(size);
    for (int i = 0; i < size; ++i) {
        prev[i] = i;
    }
}

int disjointSet::getID(int i) {
    if (prev[i] == i) return i;
    return prev[i] = getID(prev[i]);
}

int disjointSet::size() const { return size_; }
bool disjointSet::isLinked(int lhs, int rhs) {
    return getID(lhs) == getID(rhs);
}
void disjointSet::link(int lhs, int rhs) {
    lhs = getID(lhs);
    rhs = getID(rhs);
    if (rank[lhs] < rank[rhs]) {
        prev[lhs] = rhs;
    } else {
        prev[rhs] = lhs;
        if (rank[lhs] == rank[rhs]) {
            rank[lhs]++;
        }
    }
}
int main() {
    disjointSet ds(15);
    ds.link(0, 2);
    ds.link(2, 4);
    ds.link(4, 6);
    ds.link(1, 3);
    ds.link(5, 7);
    ds.link(3, 5);
    ds.link(0, 1);
    for (int i = 0; i < 15; ++i) {
        cout << i << " : " << ds.Prev(i) << endl;
    }
    return 0;
}
