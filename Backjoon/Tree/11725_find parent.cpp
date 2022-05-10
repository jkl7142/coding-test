/*
    11725 - 트리의 부모 찾기
*/

#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100'001

int n;
vector<int> tree[MAX_N];
int p[MAX_N];

void dfs(int node) {
    for (int next : tree[node]) {
        if (p[node] == next)
            continue;

        p[next] = node;
        dfs(next);
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1);

    for (int i = 2; i <= n; i++) {
        cout << p[i] << "\n";
    }

    return 0;
}