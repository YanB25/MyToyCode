#include <iostream>
#include <stdexcept>
using namespace std;
class queue {
public:
    queue();
    queue(const queue& rhs);
    ~queue();
    int size() const { return size_; }
    bool empty() const;
    bool full() const;
    void enque(int item);
    void deque();
    int front() const;
    int back() const;
    void print() const {
        int cur = front_;
        while (cur != rear_) {
            cout << data_[cur] << " ";
            cur = next(cur);
        }
        cout << endl;
    }
private:
    const int maxSize = 15;
    const int capacity = maxSize + 1;
    int next(int index) const;
    int prev(int index) const;
    int* data_;
    int size_;
    int front_;
    int rear_;
};
queue::queue() : size_(0), front_(0), rear_(0) {
    data_ = new int[capacity];
}
queue::queue(const queue& rhs) : queue() {
    for (int i = 0; i < capacity; ++i) {
        data_[i] = rhs.data_[i];
    }
}
queue::~queue() {
    delete[] data_;
    size_ = 0;
    front_ = 0;
    rear_ = 0;
}
bool queue::empty() const { return rear_ == front_; }
bool queue::full() const { return next(rear_) == front_; }
int queue::front() const { 
    if (empty()) {
        throw underflow_error("can not access front()");
    }
    return data_[front_];
}
int queue::back() const {
    if (empty()) {
        throw underflow_error("can not access back()");
    }
    return data_[prev(rear_)];
}
int queue::next(int index) const {
    if (index == capacity - 1) {
        return 0;
    }
    return index + 1;
}
int queue::prev(int index) const {
    if (index == 0) {
        return capacity - 1;
    }
    return index - 1;
}
void queue::enque(int item) {
    if (full()) {
        throw overflow_error("can not enque");
    }
    data_[rear_] = item;
    rear_ = next(rear_);
}
void queue::deque() {
    if (empty()) {
        throw underflow_error("can not deque");
    }
    front_ = next(front_);
}
int main() {
    queue qu;
    try {
        for (int i = 0; i < 20; ++i) {
            qu.enque(i);
            qu.print();
        }
    } catch(exception& e) {
        cout << e.what() << endl;
    }
    try {
        for (int i = 0; i < 20; ++i) {
            qu.deque();
            qu.print();
        }
    } catch (exception& e) {
        cout << e.what() << endl;
    }
    for (int i = 0; i < 3; ++i) {
        qu.enque(i);
    }
    for (int i = 0; i < 300; ++i) {
        qu.enque(i);
        qu.print();
        qu.deque();
        qu.print();
    }
    return 0;
}
