#include <iostream>
using namespace std;
template <class Record>

struct Node

{

         Record entry;

         Node<Record> *next;
         Node(Record e, Node<Record>* n = nullptr) {
             entry = e;
             next = n;
         }

};

 

template <class Record>

class Sortable_list

{

public:

         Sortable_list();

         ~Sortable_list();

        

         // 在第position个位置插入值为entry的元素，如果position为0则插入在链表头，以此类推

         // 输入数据中，position满足 0 <= position <= 链表元素数量

         void insert(int position, const Record &entry);

 

         // 输出链表的内容，每两个元素之间用一个空格隔开，最后一个元素之后没有空格，并且需要换行

         void print();

 

         // 对链表进行归并排序，你可以添加一些辅助函数，但不能改动类的成员变量

         void merge_sort();

private:
         Node<Record>* sort(Node<Record>*, Node<Record>*);
         Node<Record>* getMid(Node<Record>*, Node<Record>*);

         Node<Record> *head;                                     // 链表头指针

};

template <typename T>
Sortable_list<T>::Sortable_list() : head(nullptr) {}
template <typename T>
Sortable_list<T>::~Sortable_list() {
    while (head) {
        Node<T>* tar = head;
        head = head->next;
        delete tar;
    }
}

template <typename T>
void Sortable_list<T>::insert(int pos, const T& data) {
    if (pos < 0) return;
    if (pos == 0) {
        Node<T>* new_node = new Node<T>(data, head);
        head = new_node;
    } else {
        Node<T>* prev = head;
        while (--pos) {
            prev = prev->next;
        }
        Node<T>* new_node = new Node<T>(data, prev->next);
        prev->next = new_node;
    }
}

template <typename T>
void Sortable_list<T>::print() {
    Node<T>* cur = head;
    while (cur) {
        if (cur->next) {
            cout << cur->entry << " ";
        } else {
            cout << cur->entry << endl;
        }
        cur = cur->next;
    }
}


template <typename T>
void Sortable_list<T>::merge_sort() {
    head = sort(head, nullptr);
}


template <typename T>
Node<T>* Sortable_list<T>::sort(Node<T>* beg, Node<T>* end) {
    if (beg == end) return beg;
    if (beg->next == end) return beg;
    Node<T>* b1 = beg;
    Node<T>* e1 = getMid(beg, end);
    Node<T>* b2 = e1->next;
    Node<T>* e2 = end;
    e1->next = nullptr;
    e1 = nullptr;
    b1 = sort(b1, e1);
    b2 = sort(b2, e2);
    Node<T>* new_head = new Node<T>(0);
    Node<T>* cur = new_head;
    while (b1 != e1 && b2 != e2) {
        if (b1->entry < b2->entry) {
            cur->next = b1;
            b1 = b1->next;
            cur = cur->next;
        } else {
            cur->next = b2;
            b2 = b2->next;
            cur = cur->next;
        }
    }
    while (b1 != e1) {
        cur->next = b1;
        cur = cur->next;
        b1 = b1->next;
    }
    while (b2 != e2) {
        cur->next = b2;
        cur = cur->next;
        b2 = b2->next;
    }
    Node<T>* tar = new_head;
    new_head = new_head->next;
    delete tar;
    return new_head;
}
template <typename T>
Node<T>* Sortable_list<T>::getMid(Node<T>* beg, Node<T>* end) {
    if (!head) return nullptr;
    Node<T>* prev = beg;
    Node<T>* back = beg;
    while (back->next != end && back->next->next != end) {
        prev = prev->next;
        back = back->next->next;
    }
    return prev;
}
int main() {
    Sortable_list<int> ls;
    for (int i = 0; i < 10; ++i) {
        ls.insert(0, i);
    }
    ls.print();
    ls.merge_sort();
    ls.print();
    return 0;
}






