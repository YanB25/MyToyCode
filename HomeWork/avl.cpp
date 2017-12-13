#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
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
    avlNode<Entry>* delete_left(avlNode<Entry>*, bool&);
    avlNode<Entry>* delete_right(avlNode<Entry>*, bool&);
    avlNode<Entry>* getSucc(avlNode<Entry>*, avlNode<Entry>**);
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
template <typename Entry>
avlNode<Entry>* avlTree<Entry>::removeNode(avlNode<Entry>* node, const Entry& entry, bool& shorter) {
    if (node == nullptr) return nullptr;
    if (node->entry > entry) {
        node->left = removeNode(node->left, entry, shorter);
        if (shorter) node = delete_left(node, shorter);
    } else if (node->entry < entry) {
        node->right = removeNode(node->right, entry, shorter);
        if (shorter) node = delete_right(node, shorter);
    } else {
        if (node->left == nullptr) {
            avlNode<Entry>* ret = node->right;
            shorter = true;
            delete node;
            return ret;
        } else if (node->right == nullptr) {
            avlNode<Entry>* ret = node->left;
            shorter = true;
            delete node;
            return ret;
        } else {
            avlNode<Entry>* succ = nullptr;
            node->right = getSucc(node->right, &succ);
            succ->left = node->left;
            succ->right = node->right;
            delete node;
            return succ;
        }
    }
    return node;
}
template <typename Entry>
avlNode<Entry>* avlTree<Entry>::getSucc(avlNode<Entry>* node, avlNode<Entry>** ans) {
    if (node->left) {
        node->left = getSucc(node->left, ans);
    } else {
        *ans = node;
        return node->right;
    }
    return node;
}
template <typename Entry>
avlNode<Entry>* avlTree<Entry>::delete_left(avlNode<Entry>* node, bool& shorter) {
    switch(node->bf) {
        case eq:
            shorter = false;
            node->bf = rh;
            break;
        case lh:
            node->bf = eq;
            break;
        case rh:
            avlNode<Entry>* right = node->right;
            switch(right->bf) {
                case rh:
                    node->bf = eq;
                    right->bf = eq;
                    node = rotate_left(node);
                    shorter = false;
                    break;
                case eq:
                    node->bf = rh;
                    right->bf = lh;
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
    }
    return node;
}
template <typename Entry>
avlNode<Entry>* avlTree<Entry>::delete_right(avlNode<Entry>* node, bool& shorter) {
    switch(node->bf) {
        case eq:
            node->bf = lh;
            shorter = false;
            break;
        case rh:
            node->bf = eq;
            break;
        case lh:
            avlNode<Entry>* left = node->left;
            switch(left->bf) {
                case eq:
                    node->bf = lh;
                    left->bf = rh;
                    node = rotate_right(node);
                    break;
                case lh:
                    node->bf = eq;
                    left->bf = eq;
                    node = rotate_right(node);
                    shorter = false;
                    break;
                case rh:
                    avlNode<Entry>* lright = left->right;
                    switch(lright->bf) {
                        case eq:
                            node->bf = eq;
                            lright->bf = eq;
                            break;
                        case lh:
                            node->bf = rh;
                            left->bf = eq;
                            break;
                        case rh:
                            node->bf = eq;
                            left->bf = lh;
                            break;
                    }
                    lright->bf = eq;
                    left = rotate_left(left);
                    node = rotate_right(node);
            }
    }
    return node;
}
int main() {
    avlTree<int> tree;
    cout << "insert " << endl;
    for (int i = 0; i < 5; ++i) {
        tree.insert(i);
        tree.print();
    }
    cout << "remove " << endl;
    for (int i = 5; i >= 2; --i) {
        tree.remove(i);
        tree.print();
    }
//    cout << "insert " << endl;
//    for (int i = -4; i <= 0; ++i) {
//        tree.insert(i);
//        tree.print();
//    }
//    cout << "remove " << endl;
//    for (int i = -3; i <= 4; ++i) {
//        tree.remove(i);
//        tree.print();
//    }
//    
}
