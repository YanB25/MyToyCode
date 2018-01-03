#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node (int d, Node* p = nullptr, Node* n = nullptr) {
        data = d;
        prev = p;
        next = n;
    }
};
class List {
public:
    List();
    ~List();
    List(const List& rhs);
    List& operator=(List rhs);

    void insert(int pos, int data);
    void remove(int pos);
    void print() const;

    bool empty() const;
    int size() const;
    void clear();
private:
    Node* head_;
    Node* tail_;
    int size_;
    Node* getPrev(int pos);
};
List::List() : head_(nullptr), tail_(nullptr), size_(0) {}
List::~List() {
    clear();
    size_ = 0;
}
List::List(const List& rhs) {
    if (rhs.head_) {
        Node* rhs_cur = rhs.head_;
        head_ = new Node(rhs_cur->data);
        Node* cur = head_;
        while (rhs_cur->next) {
            rhs_cur = rhs_cur->next;
            cur->next = new Node(rhs_cur->data);
            cur = cur->next;
        }
        tail_ = cur;
        size_ = rhs.size_;
    }
}
List& List::operator=(List rhs) {
    std::swap(head_, rhs.head_);
    std::swap(tail_, rhs.tail_);
    std::swap(size_, rhs.size_);
    return *this;
}
Node* List::getPrev(int pos) {
    if (pos <= 0 || pos > size_) return nullptr;
    Node* cur = head_;
    while (--pos) cur = cur->next;
    return cur;
}
void List::insert(int pos, int data) {
    if (pos < 0 || pos > size_) return;
    Node* prev = getPrev(pos);
    Node* next = prev == nullptr ? head_: prev->next;
    Node* new_node = new Node(data, prev, next);
    if (prev) prev->next = new_node;
    if (next) next->prev = new_node;
    if (pos == 0) head_ = new_node;
    if (pos == size_) tail_ = new_node;
    size_++;
}
void List::remove(int pos){
    if (pos < 0 || pos >= size_) return;
    Node* prev = getPrev(pos);
    Node* tar = prev == nullptr ? head_ : prev->next;
    Node* next = tar->next;
    if (pos == 0) head_ = head_->next;
    if (pos == size_ - 1) tail_ = tail_->prev;
    if (prev) prev->next = next;
    if (next) next->prev = prev;
    size_--;
    delete tar;
}
void List::print() const {
    Node* cur = head_;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}
void List::clear() {
    while (!empty()) {
        remove(0);
    }
    size_ = 0;
}
bool List::empty() const { return size_ == 0; }
int List::size() const { return size_; }
int main() {
    List ls;
    for (int i =0; i < 3; ++i) {
        ls.insert(0, i);
        ls.print();
    }

}
