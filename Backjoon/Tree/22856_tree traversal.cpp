/*
    22856 - 트리 순회
    유사 중위 순회 이동 횟수 = 2 * 간선의 개수 - 루트에서 마지막 노드로의 이동 횟수
*/

#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100'001;

struct Tree {
    int num = -1;
    Tree* left;
    Tree* right;
} tree[MAX_N];

int n;
int node, l, r;
int lastMoveCnt = -1;

void dfs(Tree* node, bool flag) {
    if (node) {
        dfs(node->left, false);

        if (flag) {
            lastMoveCnt++;
            dfs(node->right, true);
        }
        else
            dfs(node->right, false);
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> node >> l >> r;

        tree[node].num = node;
        if (l != -1)
            tree[node].left = &tree[l];
        if (r != -1)
            tree[node].right = &tree[r];
    }

    dfs(&tree[1], true);

    cout << 2 * (n - 1) - lastMoveCnt << "\n";

    return 0;
}