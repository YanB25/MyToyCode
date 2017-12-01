#include <exception>
#include <stdexcept>
#include <iostream>
using namespace std;
template <typename T>
class Stack {
public:
    struct Node {
        T data;
        Node* next;
        Node(const T& data_, Node* next_ = nullptr) {
            data = data_;
            next = next_;
        }
    };
    Stack();
    Stack(const Stack& rhs);
    ~Stack();
    bool empty() const { return size_ == 0; }
    int size() const;
    T top() const;
    void push(const T& item);
    void pop();
    void clear();
    void print() {
        Node* cur = head;
        while(cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
private:
    Node* head;
    int size_;
};
template <typename T>
Stack<T>::Stack() : head(nullptr), size_(0) {}
template <typename T>
Stack<T>::~Stack() {
    clear();
}
template <typename T>
void Stack<T>::clear() {
    Node* cur = head;
    while (cur) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
    size_ = 0;
}
template <typename T>
int Stack<T>::size() const { return size_; }
template <typename T>
T Stack<T>::top() const { 
    if (empty()) {
        throw underflow_error("");
    }
    return head->data; 
}
template <typename T>
void Stack<T>::push(const T& item) {
    Node* new_node = new Node(item, head);
    head = new_node;
    size_++;
}
template <typename T>
void Stack<T>::pop() {
    if (empty()) {
        throw underflow_error(" error ");
    }
    Node* tar = head;
    head = head->next;
    size_--;
    delete tar;
}
int main() {
    Stack<int> s;
    for (int i = 0; i < 10; ++i) {
        s.push(i);
        s.print();
    }
    try {
        for (int i = 0; i < 20; ++i) {
            s.pop();
            s.print();
        }
    } catch(exception& e) {
        cout << e.what() << endl;
    }
    return 0;
}
