#include <iostream>
#include <algorithm>
using namespace std;
enum Error_code
{
    success,
    underflow,
    overflow
};
template <class List_entry>
struct Node
{
    List_entry entry;
    Node<List_entry> *next;
    Node<List_entry> *back;
    Node(List_entry e, Node<List_entry>* n = nullptr, Node<List_entry>* b = nullptr) {
    entry = e;
    next = n;
    back = b;
           }
};
template <class List_entry>
class MyList
{
public:
    MyList();
    ~MyList();
    // 拷贝构造函数和赋值运算符重载，注意深拷贝与浅拷贝的差异
    MyList(const MyList<List_entry> &copy);
    void operator =(MyList<List_entry> );
    // 清空list
    void clear();
    // 判断list是否为空
    bool empty() const;
    // 判断list是否已满
    bool full() const;
    // 获取list的元素数量
    int size() const;
    // 在第position个位置插入值为entry的元素，如果position为0则插入在链表头，依次类推
    // 若position < 0 或者 position > count，则返回underflow
    Error_code insert(int position, const List_entry &entry);
    // 删除第position个位置的元素，并将该元素的值保存在entry中
    // 若position < 0 或者 position >= count，则返回underflow
    Error_code remove(int position, List_entry &entry);
    // 获取第position个位置的元素，保存在entry中
    // 若position < 0 或者 position >= count，则返回underflow
    Error_code retrieve(int position, List_entry &entry) const;
    // 将第position个位置的元素替换为entry
    // 若position < 0 或者 position >= count，则返回underflow
    Error_code replace(int position, const List_entry &entry);
    // 用visit函数遍历list内所有的元素
    void traverse(void (*visit)(List_entry &));
protected:
    int count;                                                                          // 记录list内元素数量
    mutable int curPosition;                                 // current指针的位置编号
    mutable Node<List_entry> *current;                // current指针
    // 设置current指针的位置，指向第position个位置
    void setPosition(int position) const;

};
template <typename T>
MyList<T>::MyList() : count(0), curPosition(-1), current(nullptr) {}
template <typename T>
MyList<T>::~MyList() {
    clear();
}
template <typename T>
MyList<T>::MyList(const MyList<T>& rhs) {
    Node<T>* rhs_cur = rhs.current;
    Node<T>* cur = nullptr;
    curPosition = -1;
    current = nullptr;
    if (rhs_cur) {
        current = cur = new Node<T>(rhs_cur->entry, nullptr, nullptr);
        while (rhs_cur->next) {
            rhs_cur = rhs_cur->next;
            cur->next = new Node<T>(rhs_cur->entry, nullptr, cur);
            cur = cur->next;
        }
        count = rhs.count;
        curPosition = 0;
        current = current;
    }
}
template <typename T>
void MyList<T>::operator=(MyList<T> rhs) {
    swap(count, rhs.count);
    swap(curPosition, rhs.curPosition);
    swap(current, rhs.current);
}
template <typename T>
void MyList<T>::clear() {
    T t;
    while (!empty()) {
        remove(0, t);
    }
}
template <typename T>
bool MyList<T>::empty() const { return count == 0; }
template <typename T>
bool MyList<T>::full() const { return false; }
template <typename T>
int MyList<T>::size() const { return count; }
template <typename T>
Error_code MyList<T>::remove(int position,T& data) {
    if (position < 0 || position >= count) return underflow;
    setPosition(position);
    Node<T>* tar = current;
    data = tar->entry;
    Node<T>* back = tar->back;
    Node<T>* next = tar->next;
    if (count == 1) {
        curPosition = -1;
        current = nullptr;
    } else {
        if (tar->back) {
            current = tar->back;
            curPosition--;
        } else {
            current = tar->next;
        }
    }
    if (next) next->back = back;
    if (back) back->next = next;
    delete tar;
    count--;
    return success;
}
template <typename T>
Error_code MyList<T>::insert(int position,const T& data) {
    if (position < 0 || position > count) return underflow;
    if (!current) {
        current = new Node<T>(data);
        curPosition = 0;
        count = 1;
        return success;
    } else {
        if (position == 0) {
            setPosition(0);
            Node<T>* new_node = new Node<T>(data, current, nullptr);
            current->back = new_node;
            count++;
            current = new_node;
            curPosition = 0;
            return success;
        } else {
            setPosition(position-1);
            Node<T>* prev = current;
            Node<T>* next = current->next;
            Node<T>* new_node = new Node<T>(data, next, prev);
            prev->next = new_node;
            if (next) next->back = new_node;
            count++;
            return success;
        }
    }
}

template <typename T>
Error_code MyList<T>::retrieve(int position, T& entry) const {
    if (position < 0 || position >= count) return underflow;
    setPosition(position);
    entry = current->entry;
    return success;
}

template <typename T>
Error_code MyList<T>::replace(int position, const T& data) {
    if (position < 0 || position >= count) {
        return underflow;
    }
    setPosition(position);
    current->entry = data;
    return success;
}
template <typename T>
void MyList<T>::traverse(void (*visit)(T&)) {
    setPosition(0);
    Node<T>* cur = current;;
    while (cur) {
        visit(cur->entry);
        cur = cur->next;
    }
}
void printn(int& i) {
    cout << i << " ";
}
void print(MyList<int>& ls) {
    ls.traverse(printn);
    cout << endl;
}
template <typename T>
void MyList<T>::setPosition(int position) const {
    if (current) {
        if (position > curPosition) {
            for (;position != curPosition; ++curPosition) {
                current = current->next;
            }
        } else {
            for (; position!= curPosition; --curPosition) {
                current = current->back;
            }
        }
    }
}
int main() {
    MyList<int> ls;
    for (int i = 0; i < 10; ++i) {
        ls.insert(0, i);
        print(ls);
    }
    for (int i = 0; i < 10; ++i) {
        ls.insert(3, i);
        print(ls);
    }
    for (int i = 0; i < 3; ++i) {
        int j;
        ls.remove(3, j);
        cout << j << " > ";
        print(ls);
    }
    for (int i = 0; i < 5; ++i) {
        int output;
        ls.retrieve(i, output);
        cout << output << endl;
    }
    for (int i = 0; i < 5; ++i) {
        ls.replace (i, 233);
        print(ls);
    }
    MyList<int> ls2(ls);
    print(ls2);
    MyList<int> ls3;
    ls3 = ls;
    print(ls3);
    return 0;
}


