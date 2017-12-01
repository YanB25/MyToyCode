#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d, Node* l = nullptr, Node* r = nullptr) {
        data = d;
        left = l;
        right = r;
    }
};
class Tree {
public:
    Tree();
    Tree(const Tree& rhs);
    Tree& operator=(Tree tree);
    ~Tree();
    void insert(int data);
    void remove(int data);
    void print() const;
private:
    Node* root_;
    Node* copy_(Node*);
    Node* insertNode(Node* node, int data);
    void InOrder(Node* node) const;
    Node* getSucc(Node*, Node**);
    Node* removeNode(Node*, int);
    void deleteNode(Node*);
};

Tree::Tree() : root_(nullptr) {}
Tree::Tree(const Tree& rhs) : Tree() {
    root_ = copy_(rhs.root_);
}
Node* Tree::copy_(Node* rhs) {
    if (rhs == nullptr) return nullptr;
    Node* new_node = new Node(rhs->data);
    new_node->left = copy_(rhs->left);
    new_node->right = copy_(rhs->right);
    return new_node;
}

Tree::~Tree() {
    deleteNode(root_);
}
void Tree::deleteNode(Node* node) {
    if (node == nullptr) return;
    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
}
Tree& Tree::operator=(Tree tree) {
    std::swap(root_, tree.root_);
    return *this;
}

void Tree::insert(int data) {
    root_ = insertNode(root_, data);
}
Node* Tree::insertNode(Node* node, int data) {
    if (node == nullptr) return new Node(data);
    if (node->data > data) {
        node->left = insertNode(node->left, data);
    } else if (node->data < data) {
        node->right = insertNode(node->right, data);
    } 
    return node;
}

void Tree::print() const {
    InOrder(root_);
    cout << endl;
}
void Tree::InOrder(Node* node) const {
    if (node) {
        InOrder(node->left);
        cout << node->data << " ";
        InOrder(node->right);
    }
}
void Tree::remove(int data) {
    root_ = removeNode(root_, data);
}
Node* Tree::removeNode(Node* node, int data) {
    if (node == nullptr) return nullptr;
    if (node->data > data) {
        node->left = removeNode(node->left, data);
    } else if (node->data < data) {
        node->right = removeNode(node->right, data);
    } else {
        if (node->left == nullptr) {
            Node* ret = node->right;
            delete node;
            return ret;
        } else if (node->right == nullptr) {
            Node* ret = node->left;
            delete node;
            return ret;
        } else {
            Node* new_node;
            getSucc(node->right, &new_node);
            new_node->left = node->left;
            new_node->right = node->right;
            delete node;
            return new_node;
        }
    }
    return node;
}
Node* Tree::getSucc(Node* node, Node** ans) {
    if (node->left == nullptr) {
        *ans = node;
        return node->right;
    }
    node->left = getSucc(node->left, ans);
    return node;
}
int main() {
    Tree t;
    for (int i = 10; i >= 0; --i) {
        t.insert(i);
        t.print();
    }
    for (int i = 0; i < 5; ++i) {
        t.remove(i);
        t.print();
    }
    return 0;
}
