#include <iostream>
using namespace std;
#ifndef AVL_NODE
#define AVL_NODE
 
enum balance_factor { lh, rh, eq };

template <class Entry>
struct AvlNode
{
    Entry entry;
    AvlNode<Entry> *left;
    AvlNode<Entry> *right;
    balance_factor bf;	// balance factor 平衡因子
    AvlNode(const Entry& e) {
        entry = e;
        left = nullptr;
        right = nullptr;
        bf = eq;
    }
};
 
 
// 查找AVL树里面是否有元素entry，如果有则返回该结点，没有则返回NULL
template <class Entry>
AvlNode<Entry> *AVL_search(AvlNode<Entry> *&root, const Entry entry){
    if (root == nullptr) return nullptr;
    if (root->entry < entry) {
        return AVL_search(root->right, entry);
    } else if (root->entry > entry) {
        return AVL_search(root->left, entry);
    } else 
        return root;
}
 
// 将entry插入到AVL树
template <class Entry>
void AVL_insert(AvlNode<Entry> *&root, const Entry entry){
    bool taller = false;
    root = insertNode(root, entry, taller);
}

template <typename Entry>
AvlNode<Entry>* insertNode(AvlNode<Entry>* node, const Entry& entry, bool& taller) {
    if (node == nullptr) {
        taller = true;
        return new AvlNode<Entry>(entry);
    }
    if (node->entry == entry) {
        return node;
    }
    if (node->entry < entry) {
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
    }else {
        node->left = insertNode(node->left, entry, taller);
        if (taller) {
            switch(node->bf) {
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
    }
    return node;
}
#ifdef DEBUG
template <typename Entry>
void print(AvlNode<Entry>* root) {
     printNode(root);
     cout << endl;
 }
template <typename Entry>
 void printNode(AvlNode<Entry>* node) {
     if (node== nullptr) return ;
     printNode(node->left);
     cout << node->entry << " ";
     printNode(node->right);
}
#endif
template <typename Entry>
AvlNode<Entry>* rotate_left(AvlNode<Entry>* node) {
    AvlNode<Entry>* new_head = node->right;
    node->right = new_head->left;
    new_head->left = node;
    return new_head;
}
template <typename Entry>
AvlNode<Entry>* rotate_right(AvlNode<Entry>* node) {
    AvlNode<Entry>* new_head = node->left;
    node->left = new_head->right;
    new_head->right = node;
    return new_head;
}
template <typename Entry>
AvlNode<Entry>* left_balance(AvlNode<Entry>* node) {
    AvlNode<Entry>*& left = node->left;
    switch(left->bf) {
        case eq:
            cerr << "error in left_balcen" << endl;
            break;
        case lh:
            left->bf = eq;
            node->bf = eq;
            node = rotate_right(node);
            break;
        case rh:
            AvlNode<Entry>* lright = left->right;
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
AvlNode<Entry>* right_balance(AvlNode<Entry>* node) {
    AvlNode<Entry>*& right = node->right;
    switch(right->bf) {
        case eq:
            cerr << "error in right balance" << endl;
            break;
        case rh:
            node->bf = eq;
            right->bf = eq;
            node = rotate_left(node);
            break;
        case lh:
            AvlNode<Entry>* rleft = right->left;
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
                    right->bf = eq;
                    node->bf = lh;
                    break;
            }
            rleft->bf = eq;
            right = rotate_right(right);
            node = rotate_left(node);
    }
    return node;
}
#ifdef DEBUG
template <typename Entry>
void remove(AvlNode<Entry>* node) {
    if (node == nullptr) return;
    remove(node->left);
    remove(node->right);
    delete node;
}
#endif
#endif
int main() {
    AvlNode<int>* root_ = nullptr;
    for (int i = 0; i <= 4; ++i) {
        AVL_insert(root_, i);
        print(root_);
    }
    for (int i = 10; i >= 7; i--) {
        AVL_insert(root_, i);
        print(root_);
    }
    for (int i = 20; i <= 35; ++i) {
        AVL_insert(root_, i);
        print(root_);
    }
    for (int i = -10; i <= 20; ++i) {
        auto p = AVL_search(root_, i);
        if (p) cout << p->entry << endl;
    }
    remove(root_);
}
