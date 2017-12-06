#include <iostream>
using namespace std;
enum balance_factor { eq, lh, rh };
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
    void remove(const Entry& entry);
private:
    avlNode<Entry>* root_;
    avlNode<Entry>* insertNode(avlNode<Entry>*, const Entry&, bool&);
    void remove_(avlNode<Entry>*);
    void printNode(avlNode<Entry>*) const;
    avlNode<Entry>* rotate_left(avlNode<Entry>*);
    avlNode<Entry>* rotate_right(avlNode<Entry>*);
    avlNode<Entry>* left_balance(avlNode<Entry>*);
    avlNode<Entry>* right_balance(avlNode<Entry>*);
    avlNode<Entry>* removeNode(avlNode<Entry>*, const Entry&, bool&);
};
template <typename Entry>
avlTree<Entry>::~avlTree() {
    clear();
    root_ = nullptr;
}
template <typename Entry>
void avlTree<Entry>::print() const {
    printNode(root_);
    cout << endl;
}
template <typename Entry>
void avlTree<Entry>::printNode(avlNode<Entry>* node) const {
    if (node) {
        cout << node->entry << " ";
        printNode(node->left);
        printNode(node->right);
    }
}
template <typename Entry>
avlTree<Entry>::avlTree() : root_(nullptr) {}
template <typename Entry>
void avlTree<Entry>::clear() {
    remove_(root_);
    root_ = nullptr;
}
template <typename Entry>
void avlTree<Entry>::insert(const Entry& entry) {
    bool taller = true;
    root_ = insertNode(root_, entry, taller);
}
template <typename Entry>
avlNode<Entry>* avlTree<Entry>::insertNode(avlNode<Entry>* node, const Entry& entry, bool& taller) {
    if (node == nullptr) {
        taller = true;
        return new avlNode<Entry>(entry);
    }
    if (node->entry > entry) {
        node->left = insertNode(node->left, entry, taller);
        if (taller) {
            switch (node->bf) {
                case eq:
                    node->bf = lh;
                    break;
                case rh:
                    node->bf = eq;
                    taller = false;
                    break;
                case lh:
                    node = left_balance(node);
                    taller = false;
                    break;
            }
        }
    } else if (node ->entry < entry) {
        node->right = insertNode(node->right, entry, taller);
        if (taller) {
            switch(node->bf) {
                case eq:
                    node->bf = rh;
                    break;
                case lh:
                    node->bf = eq;
                    taller = false;
                    break;
                case rh:
                    node = right_balance(node);
                    taller = false;
                    break;
            }
        }
    } 
    return node;
}
template <typename Entry>
avlNode<Entry>* avlTree<Entry>::rotate_left(avlNode<Entry>* node) {
    avlNode<Entry>* right = node->right;
    node->right = right->left;
    right->left = node;
    return right;
}
template <typename Entry>
avlNode<Entry>* avlTree<Entry>::rotate_right(avlNode<Entry>* node) {
    avlNode<Entry>* left = node->left;
    node->left = left->right;
    left->right = node;
    return left;
}
template <typename Entry>
avlNode<Entry>* avlTree<Entry>::left_balance(avlNode<Entry>* node) {
    avlNode<Entry>* left = node->left;
    switch(left->bf) {
        case eq:
            cerr << "error in left balance" << endl;
            break;
        case lh:
            node->bf = eq;
            left->bf = eq;
            node = rotate_right(node);
            break;
        case rh:
            avlNode<Entry>* lright = left->right;
            switch(lright->bf) {
                case eq:
                    node->bf = eq;
                    left->bf = eq;
                    break;
                case lh:
                    left->bf = eq;
                    node->bf = rh;
                    break;
                case rh:
                    left->bf = lh;
                    node->bf = eq;
                    break;
            }
            lright->bf = eq;
            left = rotate_left(left);
            node = rotate_right(node);
    }
    return node;
}
template <typename Entry>
avlNode<Entry>* avlTree<Entry>::right_balance(avlNode<Entry>* node) {
    avlNode<Entry>* right = node->right;
    switch(right->bf) {
        case eq:
            cerr << "error in right_balance" << endl;
            break;
        case rh:
            node->bf = eq;
            right->bf = eq;
            node = rotate_left(node);
            break;
        case lh:
            avlNode<Entry>* rleft = right->left;
            switch(rleft->bf) {
                case eq:
                    node->bf = eq;
                    right->bf = eq;
                    break;
                case lh:
                    node->bf = eq;
                    right->bf = rh;
                    break;
                case rh:
                    node->bf = lh;
                    right->bf = eq;
                    break;
            }
            rleft->bf = eq;
            right = rotate_right(right);
            node = rotate_left(node);
    }
    return node;
}
template <typename Entry>
void avlTree<Entry>::remove_(avlNode<Entry>* node) {
    if (node == nullptr) return;
    remove_(node->left);
    remove_(node->right);
    delete node;
    node = nullptr;
}
template <typename Entry>
void avlTree<Entry>::remove(const Entry& entry) {
    bool shorter = true;
    root_ = removeNode(root_, entry, shorter);
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
    for (int i = 0; i >= -5; --i) {
        tree.insert(i);
        tree.print();
    }
}
