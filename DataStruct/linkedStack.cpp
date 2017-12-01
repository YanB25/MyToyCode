#include <iostream>
#include <cstddef>
#include <stdexcept>
using namespace std;
class stack {
public:
    struct Node {
        int data;
        Node* next;
        Node(int d, Node* n = nullptr) {
            data = d;
            next = n;
}
    };
    stack();
    stack(const stack& rhs);
    stack& operator=(const stack& rhs);
    ~stack();
    void clear();
    bool empty() const { return head_ == nullptr; }
    int top() const;
    bool push(int data);
    bool pop();
    int size() const { return size_; }
    void print() const {
        Node* cur = head_;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
private:
    int size_;
    Node* head_;
};
stack::stack() : size_(0), head_(nullptr) {}
stack::stack(const stack& rhs):stack() {
    (*this) = rhs;
}
stack& stack::operator=(const stack& rhs) {
    Node* new_head = nullptr; // :new_top
    Node* cur = nullptr;  // :new_copy
    Node* rhs_cur = rhs.head_; //: top_node
    if (rhs_cur) {
        new_head = cur = new Node(rhs_cur->data);
        while (rhs_cur->next) {
            rhs_cur = rhs_cur->next;
            cur->next = new Node(rhs_cur->data);
            cur = cur->next;
        }
    }
    clear();
    head_ = new_head;
    size_ =  rhs.size_;
    return (*this);
}

stack::~stack() {
    clear();
}

void stack::clear() {
    while (!empty()) {
        pop();
    }
}

int stack::top() const {
    if (empty()) {
        throw underflow_error("top()");
    }
    return head_->data;
}

bool stack::pop() {
    if (empty()) {
        return false;
    }
    Node* tar = head_;
    head_ = head_->next;
    delete tar;
    size_--;
    return false;
}
bool stack::push(int item) {
    Node* new_node = new Node(item, head_);
    head_ = new_node;
    size_++;
    return true;
}
int main() {
    stack s;
    for (int i = 0; i < 1; ++i) {
        s.push(i);
    }
    for (int i = 0; i < 100; ++i) {
        s = s;
    }
    return 0;
}
