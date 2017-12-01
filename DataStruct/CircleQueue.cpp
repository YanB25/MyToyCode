#include <iostream>
using namespace std;
const int maxSize = 10;
class Queue {
public:
    Queue();
    Queue(const Queue& rhs);
    Queue(int*, int*);
    ~Queue();
    bool enque(int);
    bool deque();
    int front() const;
    int back() const;
    void clear();
    int size() const;
    bool empty() const;
    bool full() const;
    friend ostream& operator<<(ostream& os, const Queue&q);
private:
    int head;
    int tail;
    int * buff;
};

int next(int pos) {
    pos++;
    return pos % (maxSize + 1);
}
int prev(int pos) {
    pos--;
    return pos < 0 ? pos + 6 : pos;
}
Queue::~Queue() { delete[] buff; }
Queue::Queue() : head(0), tail(0), buff(new int[maxSize + 5]) {}
Queue::Queue(const Queue& rhs) : Queue(){
    int index = rhs.head;
    while (index != rhs.tail) {
        enque(rhs.buff[index]);
        index = next(index);
    }
}

Queue::Queue(int* beg, int* end) : Queue(){
    int* cur = beg;
    while (cur != end) {
        enque(*cur);
        cur++;
    }
}

bool Queue::enque(int data) {
    if (full()) {
        return false;
    }
    buff[tail] = data;
    tail = next(tail);
    return true;
}

bool Queue::deque() {
    if (empty()) return false;
    head = next(head);
    return true;
}

int Queue::front() const {
    if (empty()) return -1;
    return buff[head];
}

int Queue::back() const {
    if (empty()) return -1;
    return buff[tail];
}

void Queue::clear() {
    while (!empty()) {
        deque();
    }
}

int Queue::size() const {
    int diff = tail - head;
    return diff < 0 ? diff + maxSize : diff;
}

bool Queue::empty() const {
    return head == tail;
}

bool Queue::full() const {
    return next(tail) == head;
}

ostream& operator<<(ostream& os, const Queue& q) {
    int index = q.head;
    while (index != q.tail) {
        os << q.buff[index] << " ";
        index = next(index);
    }
    return os;
}

int main() {
    Queue q;
    for (int i = 0; i < 100; ++i) {
        q.enque(i);
        cout << q << endl;
        q.enque(2 * i);
        cout << q << endl;
        q.deque();
        cout << q << endl;
        q.deque();
        cout << q << endl;
    }
    return 0;
}
