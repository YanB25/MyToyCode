#include <iostream>
#include <cstddef>
#include <stdexcept>
using namespace std;
class queue {
public:
    struct Node {
        int data;
        Node* next;
        Node(int d, Node* n = nullptr) {
            data = d;
            next = n;
        }
    };
    queue();
    queue(const queue& rhs);
    queue& operator=(const queue& rhs);
    ~queue();
    void clear();
    int size() const;
    bool empty() const;
    bool enque(int data);
    bool deque();
    int front() const;
    int back() const;
private:
    int size_;
    Node* front_;
    Node* rear_;
};

queue::queue() : size_(0), front_(nullptr), rear_(nullptr) {}
queue::queue(const queue& rhs) : queue() {
    (*this) = rhs;
}

