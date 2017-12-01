#ifndef AVL_NODE
#define AVL_NODE
#include <cmath>
#include <iostream>
using namespace std;
inline int max(int lhs, int rhs) { return lhs > rhs ? lhs : rhs; }
template <class Entry>
struct AvlNode
{
    Entry entry;
    AvlNode<Entry> *left;
    AvlNode<Entry> *right;
    int bf;	// balance factor 平衡因子
    AvlNode(Entry e = 0, AvlNode<Entry>* l = 0, AvlNode<Entry>* r = 0, int b = 0) {
        entry = e;
        left = l;
        right = r;
        bf = b;
    }
};
 
#endif
 
// 判断一颗树是否为平衡二叉树
template <class Entry>
bool is_AVL_Tree(AvlNode<Entry> *&root) {
    bool isavl = true;
    func(root, isavl);
    return isavl;
}
template <typename Entry>
int func(AvlNode<Entry>* node, bool& isavl) {
    if (node == nullptr) return 0;
    int left = func(node->left, isavl);
    int right = func(node->right, isavl);
    if (abs(left - right) > 1) isavl = false;
    return max(left, right) + 1;
}

#ifdef DEBUG
int main() {
    AvlNode<int>* root = new AvlNode<int>();
    root->left = new AvlNode<int>();
    root->right = new AvlNode<int>();
    cout << is_AVL_Tree(root) << endl;
}

#endif
