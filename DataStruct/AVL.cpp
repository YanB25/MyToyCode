#include <iostream>
#include <stdexcept>
#include <algorithm>
using namespace std;
int max(int a, int b) { return a > b ? a : b; }
enum Balance {eh, lh, rh};
struct Node {
    Balance balance;
    int data;
    Node* left;
    Node* right;
    Node(int d, Node* l = nullptr, Node* r = nullptr, Balance b = eh) {
        data = d;
        left = l;
        right = r;
        balance = b;
    }
};
class Tree {
public:
    Tree();
    Tree(const Tree& rhs);
    Tree& operator=(Tree tree);
    ~Tree();

    void clear();
    void insert(int data);
    void remove(int data);
    bool empty() const;
    int size() const;
    void inOrder() const;
    int tall() const;
private:
    bool taller;
    Node* copy(Node* rhs);
    void clearNode(Node*);
    int countSize(Node*)const ;
    void inOrderTraverse(Node*)const ;
    Node* insertData(int, Node*);
    Node* removeNode(int, Node*);
    Node* findMinPutOut(Node*, Node**);
    Node* root_;
    Node* balance_right(Node* node);
    Node* balance_left(Node* node);
    Node* rotate_left(Node* node);
    Node* rotate_right(Node* node);
    int tall_(Node*)const;
};
Tree::Tree() : root_(nullptr) {}
Tree::Tree(const Tree& rhs) : Tree() {
    root_ = copy(rhs.root_);
}
Node* Tree::copy(Node* rhs) {
    if (rhs == nullptr) return nullptr;
    Node* new_node = new Node(rhs->data);
    new_node->left = copy(rhs->left);
    new_node->right = copy(rhs->right);
    return new_node;
}
Tree& Tree::operator=(Tree rhs) {
    std::swap(root_, rhs.root_);
    return *this;
}
Tree::~Tree() {
    clear();
}
void Tree::clear() {
    clearNode(root_);
    root_ = nullptr;
}

void Tree::clearNode(Node* node) {
    if (node == nullptr) return;
    clearNode(node->left);
    clearNode(node->right);
    delete node;
    node = nullptr;
}
bool Tree::empty() const { return root_ == nullptr; }
int Tree::size() const {
    return countSize(root_);
}
int Tree::countSize(Node* node)const {
    if (node == nullptr) return 0;
    return countSize(node->left) + countSize(node->right) + 1;
}
void Tree::inOrder() const {
    inOrderTraverse(root_);
    cout << endl;
}
void Tree::inOrderTraverse(Node* node)const {
    if (node == nullptr) return;
    inOrderTraverse(node->left);
    cout << node->data << " ";
    inOrderTraverse(node->right);
}
void Tree::insert(int data) {
    taller = false;
    root_ = insertData(data, root_);
}
Node* Tree::insertData(int data, Node* node) {
    if (node == nullptr) {
        taller = true;
        return new Node(data);
    }
    if (node->data > data) {
        node->left = insertData(data, node->left);
        if (taller) {
            Balance b = node->balance;
            if (b == eh) {
                node->balance = lh;
                taller = false;
            } else if (b == rh) {
                node->balance = eh;
            } else {
                node = balance_left(node);
                taller = false;
            }
        }
    } else if (node->data < data) {
        node->right = insertData(data, node->right);
        if (taller) {
            Balance b = node->balance;
            if (b == lh) {
                node->balance = eh;
                taller = false;
            } else if (b == eh) {
                node->balance = rh;
            } else {
                node = balance_right(node);
                taller = false;
            }
        }
    } else {}
    return node;
}
void Tree::remove(int data) {
    root_ = removeNode(data, root_);
}
Node* Tree::removeNode(int data, Node* node) {
    if (node == nullptr) return nullptr;
    if (node->data > data) {
        node->left = removeNode(data, node->left);
    } else if (node->data < data) {
        node->right = removeNode(data, node->right);
    } else {
        if (node->left == nullptr) {
            Node* ret = node->right;
            delete node;
            return ret;
        } 
        if (node->right == nullptr) {
            Node* ret = node->left;
            delete node;
            return ret;
        }
        Node* succ = nullptr;
        node->right = findMinPutOut(node->right, &succ);
        succ->left = node->left;
        succ->right = node->right;
        delete node;
        return succ;
    }
    return node;
}
            
Node* Tree::findMinPutOut(Node* node, Node** succ) {
    if (node->left == nullptr) {
        *succ = node;
        return node->right;
    }
    node->left = findMinPutOut(node->left, succ);
    return node;
}
Node* Tree::balance_right(Node* node) {
    Node* right = node->right;
    switch (right->balance) {
        case rh:
            node->balance = eh;
            right->balance = eh;
            node = rotate_left(node);
            break;
        case eh:
            cerr << "error detect in balance_right" << endl;
            break;
        case lh:
            Node* rightLeft = right->left;
            switch(rightLeft->balance) {
                case eh:
                    node->balance = eh;
                    right->balance = eh;
                    break;
                case lh:
                    node->balance = eh;
                    rightLeft->balance = rh;
                    break;
                case rh:
                    node->balance = lh;
                    rightLeft->balance = eh;
                    break;
            }
            right->balance = eh;
            right = rotate_right(right);
            node = rotate_left(node);
    }
    return node;
}
Node* Tree::balance_left(Node* node) {
    Node* left = node->left;
    switch(left->balance) {
        case lh:
            node->balance = eh;
            left->balance = eh;
            node = rotate_right(node);
            break;
        case eh:
            cerr << "error detect in balance_left" << endl;
            break;
        case rh:
            Node* leftRight = left->right;
            switch(leftRight->balance) {
                case eh:
                    node->balance = eh;
                    leftRight->balance = eh;
                    break;
                case lh:
                    left->balance = eh;
                    node->balance = rh;
                    break;
                case rh:
                    left->balance = lh;
                    node->balance = eh;
                    break;
            }
            leftRight->balance = eh;
            left = rotate_left(left);
            node = rotate_right(node);
    }
    return node;
}

Node* Tree::rotate_left(Node* node) {
    Node* new_head = node->right;
    node->right = new_head->left;
    new_head->left = node;
    return new_head;
}
Node* Tree::rotate_right(Node* node) {
    Node* new_head = node->left;
    node->left = new_head->right;
    new_head->right = node;
    return new_head;
}
int Tree::tall() const {
    return tall_(root_);
}
int Tree::tall_(Node* node) const {
    if (node == nullptr) return 0;
    return max(tall_(node->left), tall_(node->right)) + 1;
}
int main() {
    Tree t;
    int arr[20];
    for (int i = 0; i < 20; ++i) arr[i] = i;
    for (auto i : arr) {
        t.insert(i);
        t.inOrder();
        cout << "tall "<< t.tall() << endl;
    }
    for (int i = 0; i < 5; ++i) {
        t.remove(i);
        t.inOrder();
        cout << t.size() << endl;
    }
    Tree t2(t);
    t2.inOrder();
    Tree t3;
    t3 = t;
    t3.inOrder();
    t = t;

    t.inOrder();
    for (int i = 0; i < 10; ++i) {
        t.remove(i);
        t.inOrder();
    }
    return 0;
}
