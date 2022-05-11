/*
    1991 - 트리 순회
*/

#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 27

struct Tree {
    char alpha;
    Tree* left;
    Tree* right;
} tree[MAX_N];

int n, id;
char node, lNode, rNode;

void preorder(Tree* node) {
    if (node) {
        cout << node->alpha;
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(Tree* node) {
    if (node) {
        inorder(node->left);
        cout << node->alpha;
        inorder(node->right);
    }
}

void postorder(Tree* node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        cout << node->alpha;
    }
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        
        cin >> node >> lNode >> rNode;
        id = (int)(node - 'A');

        tree[id].alpha = node;
        if (lNode != '.')
            tree[id].left = &tree[(int)(lNode - 'A')];
        if (rNode != '.')
            tree[id].right = &tree[(int)(rNode - 'A')];
    }

    preorder(tree);
    cout << "\n";
    inorder(tree);
    cout << "\n";
    postorder(tree);

    return 0;
}