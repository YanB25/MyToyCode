#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
class heap {
public:
    heap();
    heap(const heap& rhs);
    heap& operator=(heap rhs);
    ~heap();
    void clear();
    void push(int );
    void pop();
    int top() const;
    void sort();
    void print() const;
    bool empty() const;
    bool full() const;
    int size() const;
private:
    const int maxSize = 100;
    int* buff_;
    void floatUp(int);
    void sinkDown(int);
};

heap::heap() : buff_(new int[maxSize + 5]) {
    buff_[0] = 0;
}
heap::heap(const heap& rhs) : heap() {
    int size = rhs.buff_[0];
    memcpy(buff_, rhs.buff_, size * sizeof(int));
}
heap& heap::operator=(heap rhs) {
    std::swap(buff_, rhs.buff_);
    return *this;
}
heap::~heap() {
    clear();
    delete[] buff_;
}
void heap::clear() {
    buff_[0] = 0;
}
int heap::top() const { return buff_[1]; }
void heap::print() const {
    int size = buff_[0];
    for (int i = 1; i <= size; ++i) {
        cout << buff_[i] << " ";
    }
    cout << endl;
}
bool heap::empty() const { return buff_[0] == 0; }
bool heap::full() const { return buff_[0] == maxSize; }
int heap::size() const { return buff_[0]; }
void heap::push(int data) {
    if (full()) return;
    int size = ++buff_[0];
    buff_[size] = data;
    floatUp(size);
}
void heap::pop() {
    if (empty()) return;
    int size = buff_[0];
    swap(buff_[1], buff_[size]);
    buff_[0]--;
    sinkDown(1);
}
void heap::floatUp(int index) {
    while (index / 2 >= 1) {
        int f = index / 2;
        if (buff_[f] < buff_[index]) {
            std::swap(buff_[f], buff_[index]);
        }
        index /= 2;
    }
}
void heap::sinkDown(int index) {
    int size = buff_[0];
    int m = buff_[index];
    if (index * 2 <= size) m = max(m, buff_[index * 2]);
    if (index * 2 + 1 <= size) m = max(m, buff_[index * 2 + 1]);
    if(m != buff_[index]) {
        if (m == buff_[index * 2]) {
            std::swap(buff_[index], buff_[index * 2]);
            sinkDown(index * 2);
        } else {
            std::swap(buff_[index], buff_[index * 2 + 1]);
            sinkDown(index * 2 + 1);
        }
    }
}

void heap::sort() {
    int size = buff_[0];
    while (!empty()) {
        pop();
    }
    buff_[0] = size;
}

int main() {
    heap h;
    int arr[] = {1,3,5,6,4,4,3,2,6,3,4,5,6,7,8,7,5,3,2,1};
    for (auto i : arr) {
        h.push(i);
        h.print();
    }
    h.print();
    while (!h.empty()) {
        h.pop();
        h.print();
    }
}
