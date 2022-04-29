/*
    5567 - 결혼식
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_N 501

int n, m, ans;
vector<int> Friend[MAX_N];
int visited[MAX_N];

int main() {

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        Friend[a].push_back(b);
        Friend[b].push_back(a);
    }

    visited[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : Friend[cur]) {
            if (!visited[next] && visited[cur] < 3) {
                q.push(next);
                visited[next] = visited[cur] + 1;
                ans++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}