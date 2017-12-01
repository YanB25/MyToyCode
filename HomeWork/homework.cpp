#include <iostream>
using namespace std;
struct Node{
    Node* left;
    Node* right;
    int data;
    Node(int d, Node* l = nullptr, Node* r = nullptr) {
        data = d;
        left = l;
        right = r;
    }
};
class RHTree {
public:
    RHTree();
    void insert(int data);
    void inOrder(Node*);
    void preOrder(Node*);
    void postOrder(Node*);
    Node* getRoot() { return root; }
    ~RHTree();
private:
    Node* root;
    void del(Node*);
};
RHTree::~RHTree() {
    del(root);
}
void RHTree::del(Node* node) {
    if (node == nullptr) return;
    del(node->left);
    del(node->right);
    delete node;
    node = nullptr;
}
RHTree::RHTree() : root(nullptr) {}
void RHTree::insert(int data) {
    if (root == nullptr) {
        root = new Node(data);
        return;
    }
    Node** cur = &root;
    while (*cur != nullptr) {
        if ((*cur)->data >= data) {
            cur = &((*cur)->left);
        } else if ((*cur)->data < data) {
            cur = &((*cur)->right);
        }
    }
    *cur = new Node(data);
}

void RHTree::inOrder(Node* node) {
    if (node == nullptr) return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}
void RHTree::preOrder(Node* node) {
    if (node == nullptr) return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}
void RHTree::postOrder(Node* node) {
    if (node == nullptr) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}
#include <iostream>

int main() {
  int count;
  std::cin >> count;
  int x;
  RHTree tree;
  while (count--) {
    std::cin >> x;
    tree.insert(x);
  }

  std::cout << "Inorder:";
  tree.inOrder(tree.getRoot());
  std::cout << std::endl;
  std::cout << "Preorder:";
  tree.preOrder(tree.getRoot());
  std::cout << std::endl;
  std::cout << "Postorder:";
  tree.postOrder(tree.getRoot());
  std::cout << std::endl;
  return 0;
}
