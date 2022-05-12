/*
    1068 - 트리
*/

#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 51;

int n, root, par, removeNode;
vector<int> tree[MAX_N];

int dfs(int node) {
    int leafCnt = 0;

    for (auto child : tree[node]) {
        if (child == removeNode)
            continue;
        leafCnt += dfs(child);
    }

    if (leafCnt > 0)
        return leafCnt;
    else
        return 1;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> par;
        if (par == -1)
            root = i;
        else
            tree[par].push_back(i);
    }

    cin >> removeNode;
    
    if (root == removeNode)
        cout << 0 << "\n";
    else
        cout << dfs(root) << "\n";

    return 0;
}