/*
    15681 - 트리와 쿼리

def makeTree(currentNode, parent) :
    for(Node in connect[currentNode]) :
        if Node != parent:
            add Node to currentNode’s child
            set Node’s parent to currentNode
            makeTree(Node, currentNode)

def countSubtreeNodes(currentNode) :
    size[currentNode] = 1 // 자신도 자신을 루트로 하는 서브트리에 포함되므로 0이 아닌 1에서 시작한다.
    for Node in currentNode’s child:
        countSubtreeNode(Node)
        size[currentNode] += size[Node]
*/

#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100'001

int n, r, q;
int u, v;
vector<int> graph[MAX_N];
int dp[MAX_N];

int dfs(int node, int parent) {
    int childCnt = 0;

    for (int next : graph[node]) {
        if (next == parent)
            continue;

        childCnt += dfs(next, node);
    }

    return dp[node] = childCnt + 1;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(r, 0);

    for (int i = 0; i < q; i++) {
        cin >> u;

        cout << dp[u] << "\n";
    }

    return 0;
}