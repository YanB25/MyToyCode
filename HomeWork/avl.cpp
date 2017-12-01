#include <iostream>
using namespace std;
template <typename Entry>
struct avlNode {
    Entry entry;
    avlNode* left = nullptr;
    avlNode* right = nullptr;
    balance_factor bf = eq;
    avlNode(const Entry& e) {
        entry = e;
    }
};

template <typename Entry>
class avlTree {
public:
    avlTree();
    void clear();
    ~avlTree();
    void insert(const Entry& entry);
    void print() const;
private:
    avlNode<Entry>* root_;
    avlNode<Entry>* insertNode(avlNode<Entry>*, const Entry&, bool&);
    void remove_(avlNode<Entry>*);
    void printNode(avlNode<Entry>*) const;
    void rotate_left(avlNode<Entry>*&);
    void rotate_right(avlNode<Entry>*&);
    void left_balance(avlNode<Entry>*&);
    void right_balance(avlNode<Entry>*&);
};
template <typename Entry>
avlTree<Entry>::~avlTree() {
    clear();
    root_ = nullptr;
}
template <typename Entry>
avlTree<Entry>::avlTree() : root_(nullptr) {}
template <typename Entry>
void avlTree<Entry>::clear() {
    remove_(root_);
    root_ = nullptr;
}
template <typename Entry>
void avlTree<Entry>::remove_(avlNode<Entry>* node) {
    if (node == nullptr) return;
    remove_(node->left);
    remove_(node->right);
    delete node;
    node = nullptr;
}


int main() {
    avlTree<int> tree;
    for (int i = 10; i >= 0; --i) {
        tree.insert(i);
        tree.print();
    }
    for (int i = 11; i <= 20; ++i) {
        tree.insert(i);
        tree.print();
    }
}
