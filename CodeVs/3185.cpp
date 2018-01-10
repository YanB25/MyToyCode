#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node (int d, Node* n = 0) {
        data = d;
        next = n;
    }
};
class Queue {
public:
    Queue();
    void push(int d);
    void pop();
    int top() const { return front_->data; }
    bool empty() const { return front_ == 0; }
    ~Queue();
private:
    Node* front_;
    Node* rear_;
};
Queue::Queue() : front_(0), rear_(0) {}
Queue::~Queue() {
    while (front_) {
        pop();
    }
}
void Queue::push(int d) {
    if (!front_) {
        Node* new_node = new Node(d);
        front_ = rear_ = new_node;
    } else {
        Node* new_node = new Node(d);
        rear_->next = new_node;
        rear_ = new_node;
    }
}
void Queue::pop() {
    Node* tar = front_;
    front_ = front_->next;
    if (front_ == 0) rear_ = 0;
    delete tar;
}


int main() {
    int n;
    cin >> n;
    Queue q;
    bool impo = false;
    for (int i = 0; i < n; ++i) {
        if (impo) continue;
        int op;
        cin >> op;
        if (op == 2) {
            if (q.empty()) {
                impo = true;
            } else {
                q.pop();
            }
        }
        else {
            int num;
            cin >> num;
            q.push(num);
        }
    }
    if (impo || q.empty()) {
        cout << "impossible!\n";
    } else {
        cout << q.top() << endl;
    }
}
