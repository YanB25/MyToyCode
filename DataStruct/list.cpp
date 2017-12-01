#include <iostream>
#include <algorithm>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int d, Node* n = nullptr) {
        data = d;
        next = n;
    }
};

class List {
public:
    List();
    List(const List& rhs);
    List& operator=(List ls);
    ~List();
    void clear();
    void insert(int data, int pos);
    void remove(int pos);
    void print() const;
    bool empty() const;
    void mergeSort();
private:
    Node* head_;
    int size_;
    Node* getPrev(int pos);
    Node* sort_(Node* node);
    Node* getSecond(Node*);
};
List::List() : head_(nullptr), size_(0) {}
List::List(const List& rhs) : List() {
    Node* rhs_cur = rhs.head_;
    if (rhs_cur) {
        Node* new_head = new Node(rhs_cur->data);
        Node* cur = new_head;
        while (rhs_cur->next) {
            rhs_cur = rhs_cur->next;
            cur->next = new Node(rhs_cur->data);
            cur = cur->next;
        }
        head_ = new_head;
    }
    size_ = rhs.size_;    
}
List& List::operator=(List ls) {
    std::swap(head_, ls.head_);
    std::swap(size_, ls.size_);
    return *this;
}

bool List::empty() const { return size_ == 0; }
void List::clear() {
    while (!empty()) {
        remove(0);
    }
}
List::~List() {
    clear();
}
void List::print() const {
    Node* cur = head_;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}
void List::insert(int data, int pos) {
    if (pos < 0 || pos > size_) return;
    if (pos == 0) {
        Node* new_node = new Node(data, head_);
        head_ = new_node;
        size_++;
    } else {
        Node* prev = getPrev(pos);
        Node* new_node = new Node(data, prev->next);
        prev->next = new_node;
        size_++;
    }
}
void List::remove(int pos) {
    if (pos < 0 || pos >= size_) return;
    if (pos == 0) {
        Node* tar = head_;
        head_ = head_->next;
        delete tar;
    } else {
        Node* prev = getPrev(pos);
        Node* tar = prev->next;
        prev->next = tar->next;
        delete tar;
    }
    size_--;
}
Node* List::getPrev(int pos) {
    if (pos <= 0 || pos > size_) return nullptr;
    Node* cur = head_;
    while (--pos) cur = cur->next;
    return cur;
}
void List::mergeSort() {
    if (head_) {
        head_ = sort_(head_);
    }
}
Node* List::sort_(Node* node) {
    if (node == nullptr || node->next == nullptr) return node;
    Node* first = node;
    Node* second = getSecond(node);
    first = sort_(first);
    second = sort_(second);
    Node* aftersort = new Node(0);
    Node* aftersort_head = aftersort;
    while (first && second) {
        if (first->data <= second->data) {
            aftersort->next = first;
            aftersort = aftersort->next;
            first = first->next;
        } else {
            aftersort->next = second;
            aftersort = aftersort->next;
            second = second->next;
        }
    }
    if (first) aftersort->next = first;
    if (second) aftersort->next = second;
    Node* tar = aftersort_head;
    aftersort_head = aftersort_head->next;
    delete tar;
    return aftersort_head;
}
Node* List::getSecond(Node* node) {
    if (!node) return nullptr;
    Node* front = node;
    Node* back = node;
    while (back && back->next && back->next->next) {
        back = back->next->next;
        front = front->next;
    }
    Node* ret = front->next;
    front->next = nullptr;
    return ret;
}

int main() {
    List ls;
    for (int i = 0; i < 5; ++i ){
        ls.insert(i, 0);
        ls.print();
    }
    for (int i = 0; i < 5; ++i) {
        ls.insert(i, 3);
        ls.print();
    }
    ls.mergeSort();
    ls.print();
    return 0;
}
