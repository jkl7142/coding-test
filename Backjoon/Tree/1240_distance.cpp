/*
    1240 - 노드사이의 거리
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAX_N 1001

struct Edge {
    int v;
    int dist;
};

int n, m;
int u, v, d;
vector<Edge> graph[MAX_N];
bool visited[MAX_N];

int bfs(int src, int dst) {
    memset(visited, false, sizeof(visited));
    queue<Edge> q;

    visited[src] = true;
    q.push({src, 0});
    while (!q.empty()) {
        Edge cur = q.front();
        q.pop();

        if (cur.v == dst)
            return cur.dist;

        for (Edge next : graph[cur.v]) {
            if (!visited[next.v]) {
                visited[next.v] = true;
                q.push({next.v, cur.dist + next.dist});
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> d;
        
        graph[u].push_back({v, d});
        graph[v].push_back({u, d});
    }

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        cout << bfs(u, v) << "\n";
    }

    return 0;
}