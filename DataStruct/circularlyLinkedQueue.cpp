#include <iostream>
#include <cstddef>
#include <stdexcept>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int d, Node* n = nullptr) {
        data = d;
        next = n;
    }
};
class queue {
public:
    queue();
    queue(const queue& rhs);
    queue& operator=(queue);
    ~queue();
    
    void clear();
    bool empty() const;
    int size() const;
    void enque(int data);
    void deque();
    int front() const;
    int back() const;
    
    void print() const;
private:
    Node* rear_;
    int size_;
};
queue::queue() : rear_(nullptr), size_(0) {}
queue::queue(const queue& rhs) : queue() {
    Node* rhs_cur = rhs.rear_;
    Node* end = rhs_cur;
    Node* cur = rear_;
    if (rhs_cur) {
        rear_ = cur = new Node(rhs_cur->data);
        while (rhs_cur->next != end) {
            rhs_cur = rhs_cur->next;
            cur->next = new Node(rhs_cur->data);
            cur = cur->next;
        }
    }
    cur->next = rear_;
    size_ = rhs.size_;
}

queue& queue::operator=(queue rhs) { //传参时调用复制构造函数
    std::swap(rear_, rhs.rear_); // 以下两行是浅复制
    std::swap(size_, rhs.size_);
    return (*this);
} //这个大括号结束了代码块， 此时变量rhs已经是×this了。会自动调用rhs（实际是this）的析构函数
queue::~queue() {
    clear();
}

void queue::clear() {
    while (!empty()) {
        deque();
    }
}
bool queue::empty() const { return rear_ == nullptr; }
int queue::size() const { return size_; }
void queue::enque(int data) {
    if (empty()) {
        Node* new_node = new Node(data);
        rear_ = new_node;
        rear_->next = new_node;
        size_++;
    } else {
        Node* new_node = new Node(data, rear_->next);
        rear_->next = new_node;
        rear_ = new_node;
        size_++;
    }
}
void queue::deque() {
    if (empty()) {
        throw underflow_error("deque()");
    }
    if (rear_->next == rear_) {
        delete rear_;
        rear_ = nullptr;
        size_ = 0;
    } else {
        Node* tar = rear_->next;
        rear_->next = tar->next;
        delete tar;
        size_--;
    }
}
int queue::front() const {
    if (empty()) {
        throw underflow_error("front()");
    }
    return rear_->next->data;
}
int queue::back() const {
    if (empty()) {
        throw underflow_error("back()");
    }
    return rear_->data;
}

void queue::print() const {
    if (rear_) {
        Node* cur = rear_->next;
        Node* end = rear_;
        while (cur != end) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << cur->data << " ";
        cout << endl;
    }
}
int main() {
    queue q;
    for (int i = 0; i < 10; ++i) {
        q.enque(i);
        q.print();
    }
    for (int i = 0; i < 5; ++i) {
        q.deque();
        q.print();
    }
    for (int i = 5; i < 10; ++i) {
        q.enque(i);
        q.print();
    }
    queue q2(q);
    q2.print();
    queue q3;
    q3 = q2;
    q2.print();
    q = q;
    q.print();
    return 0;
}

