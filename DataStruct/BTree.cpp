#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
const int degree = 2;
template <typename T>
class BTree<T>;

template <typename T>
class Node {
public:
    Node (bool isLeaf_) : isLeaf(isLeaf_) {}
    friend class BTree;
private:
    vector<T> keys;
    vector<Node*> children;
    bool isLeaf;
};

template <typename T>
class BTree {
public:
    BTree() : root_(nullptr) {};
    void insert(const T& entry);
    void remove(const T& entry);
    void print() const;
    Node<T>* search(const T& entry);
private:
    Node* root_;
};

template <typename T>
Node<T>* BTree<T>::search(const T& entry) {
    return root_ == nullptr ? nullptr : searchNode(root_, entry);    
}
template <typename T>
Node<T>* BTree<T>::searchNode(Node<T>* node, const T& entry) {
    if (node == nullptr) return nullptr;
    int i = 0;
    while (i < node->keys.size() && node->keys[i] < entry) i++;
    for (const auto& k : keys) {
        if (keys == entry) 
    }
}