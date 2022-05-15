/*
    20955 - 민서의 응급 수술
*/

#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100'001;

int n, m, u, v, ans, cnt;
vector<int> graph[MAX_N];
bool visited[MAX_N];
bool cycle[MAX_N];

void dfs(int node, int par) {
    visited[node] = true;

    for (int next : graph[node]) {
        if (!visited[next])
            dfs(next, node);
        else if (!cycle[next] && next != par)
            cnt++;
    }
    cycle[node] = true;
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, 0);
            ans++;
        }
    }

    // 연결요소의 개수 - 1 + 사이클 개수
    cout << ans - 1 + cnt << "\n";

    return 0;
}