#include <iostream>
using namespace std;
struct Node {
    Node* next;
    int data;
    Node(int d, Node* n = nullptr) {
        data = d;
        next = n;
    }
};
class List {
public:
    List();
    ~List();
    void clear();
    void insert(int pos, int data);
    void remove(int pos);
    void mergeSort();
    bool empty() const;
    void print() const;
private:
    Node* head_;
    Node* mergeSort_(Node*);
    Node* merge(Node*, Node* );
    Node* findMid(Node*);
};
List::List() : head_(nullptr) {}
List::~List() {
    clear();
}
void List::clear() {
    while (!empty()) {
        remove(0);
    }
}
bool List::empty() const { return head_ == nullptr; }
void List::insert(int pos, int data) {
    if (pos < 0) return;
    if (pos == 0) {
        Node* new_node = new Node(data, head_);
        head_ = new_node;
    } else {
        Node* prev = head_;
        while (--pos) prev = prev->next;
        Node* new_node = new Node(data, prev->next);
        prev->next = new_node;
    }
}
void List::remove(int pos) {
    if (pos < 0) return;
    if (pos == 0) {
        Node* tar = head_;
        head_ = head_->next;
        delete tar;
    } else {
        Node* prev = head_;
        while (--pos) prev = prev->next;
        Node* tar = prev->next;
        prev->next = tar->next;
        delete tar;
    }
}
void List::mergeSort() {
    if (head_) {
        head_ = mergeSort_(head_);
    }
}
Node* List::mergeSort_(Node* node) {
    if (node == nullptr || node->next == nullptr)return node;
    Node* first = node;
    Node* second = findMid(first);
    first = mergeSort_(first);
    second = mergeSort_(second);
    return merge(first, second);
}
Node* List::merge(Node* lhs, Node* rhs) {
    Node* head = new Node(0);
    Node* cur = head;
    while (lhs != nullptr && rhs != nullptr) {
        if (lhs->data <= rhs->data) {
            cur->next = lhs;
            lhs = lhs->next;
            cur = cur->next;
        } else {
            cur->next = rhs;
            rhs = rhs->next;
            cur = cur->next;
        }
    }
    if (lhs) {
        cur->next = lhs;
    } 
    if (rhs) {
        cur->next = rhs;
    }
    Node* tar = head;
    head = head->next;
    delete tar;
    return head;
}
Node* List::findMid(Node* node) {
    if (node == nullptr) return node;
    Node* first = node;
    Node* second = node;
    while (second->next && second->next->next) {
        first = first->next;
        second = second->next->next;
    }
    Node* ret = first->next;
    first->next = nullptr;
    return ret;
}
void List::print() const {
    Node* cur = head_;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}
int main() {
    List ls;
    int arr[] = {1,4,23,2,4,5,6,7,8,5,4,3,1,2,4,5,7,8,5,3,21,2,5,7,8,1};
    for (auto i : arr) {
        ls.insert(0, i);
    }
    ls.print();
    ls.mergeSort();
    ls.print();
    return 0;
}
