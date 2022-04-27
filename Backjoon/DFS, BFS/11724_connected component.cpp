/*
    11724 - 연결 요소의 개수
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 1001

int n, m, ans;
vector<int> edge[MAX_N];
bool visited[MAX_N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i])
            continue;

        ans++;

        queue<int> q;
        q.push(i);
        visited[i] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int next : edge[cur]) {
                if (!visited[next]) {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
    }

    cout << ans;

    return 0;
}