#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node (int d, Node* n = nullptr) {
        data = d;
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
    void traverse(void (*)(int&));
    void print() const;

    bool empty() const;
    int size() const;
    void clear();
private:
    Node* head_;
    int size_;
};
List::List() : head_(nullptr), size_(0) {}
List::~List() {
    clear();
}
List::List(const List& rhs) : List() {
    if (rhs.head_) {
        Node* rhs_cur = rhs.head_;
        head_ = new Node(rhs_cur->data);
        Node* cur = head_;
        while (rhs_cur->next) {
            rhs_cur = rhs_cur->next;
            cur->next = new Node(rhs_cur->data);
            cur = cur->next;
        }
        size_ = rhs.size_;
    }
}
List& List::operator=(List rhs) {
    std::swap(head_, rhs.head_);
    std::swap(size_, rhs.size_);
    return *this;
}
void List::insert(int pos, int data) {
    if (pos < 0 || pos > size_) {
        throw overflow_error("error");
    }
    if (pos == 0) {
        Node* new_node = new Node(data, head_);
        head_ = new_node;
    } else {
        Node* cur = head_;
        while (--pos) cur = cur->next;
        Node* new_node = new Node(data, cur->next);
        cur->next = new_node;
    }
    size_++;
}

void List::remove(int pos) {
    if (pos < 0 || pos >= size_) {
        throw overflow_error("e");
    }
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
    size_--;
}

void List::print() const {
    Node* cur = head_;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}
bool List::empty() const { return size_ == 0; }
int List::size()const { return size_; }
void List::clear() {
    while (!empty()) {
        remove(0);
    }
}
void List::traverse(void (*p)(int& )) {
    Node* cur = head_;
    while (cur) {
        p(cur->data);
        cur = cur->next;
    }
}
void addone(int& i) { i++; }
int main() {
    List ls;
    for (int i = 0; i <  4; ++i) {
        ls.insert(0, i);
        ls.print();
    }
    for (int i = 6; i <= 10; ++i) {
        ls.insert(2, i);
        ls.print();
    }
    for (int i = 0; i < 3; ++i) {
        ls.remove(i);
        ls.print();
    }
    List ls2(ls);
    ls2.print();
    ls2 = ls2;
    ls2.print();
    ls2.traverse(addone);
    ls2.print();
}
