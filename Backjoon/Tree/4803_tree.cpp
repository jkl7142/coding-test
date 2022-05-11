/*
    4803 - 트리
*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MAX_N 501

int t = 1, cnt;
int n, m, u, v;
vector<int> graph[MAX_N];
bool visited[MAX_N];

void init() {
    cnt = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= MAX_N; i++)
        graph[i] = {};
}

bool dfs(int node, int par) {
    visited[node] = true;

    for (int next : graph[node]) {
        if (next == par)    // 이전 노드는 무시
            continue;
        if (visited[next]) // cycle 존재
            return false;
        if (!dfs(next, node))
            return false;
    }

    return true;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true) {

        init();

        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                if (dfs(i, 0))  // true면 트리
                    cnt++;
            }                
        }

        cout << "Case " << t++ << ": ";
        if (cnt == 0)
            cout << "No trees.\n";
        else if (cnt == 1)
            cout << "There is one tree.\n";
        else
            cout << "A forest of " << cnt << " trees.\n";
    }

    return 0;
}