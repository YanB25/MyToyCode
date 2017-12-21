#include <vector>
using std::vector;
struct directNode {
    int data;
    vector<int> next;
    bool operator<(const directNode& rhs) const { return data < rhs.data; }
    void linkto(int dst) {
        next.push_back(dst);
    }
};