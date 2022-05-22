/*
    1941 - 소문난 칠공주
*/

#include <iostream>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

const int MAX_N = 5;

int ans;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string board[MAX_N];
bool isSelected[MAX_N * MAX_N];

bool bfs() {
    bool isPrin[MAX_N][MAX_N];
    bool visited[MAX_N][MAX_N];
    queue<pair<int, int>> q;

    memset(isPrin, false, sizeof(isPrin));
    memset(visited, false, sizeof(visited));

    pair<int, int> prin;
    for (int i = 0; i < MAX_N * MAX_N; i++) {
        if (isSelected[i]) {
            prin.first = i / 5;
            prin.second = i % 5;
            isPrin[prin.first][prin.second] = true;
        }
    }

    int cnt = 1;
    q.push({prin});
    visited[prin.first][prin.second] = true;
    while (!q.empty()) {
        pair<int, int> cur = { q.front().first, q.front().second };
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.first + dy[dir];
            int nx = cur.second + dx[dir];

            if (ny < 0 || ny >= MAX_N || nx < 0 || nx >= MAX_N
                || visited[ny][nx])
                continue;

            if (isPrin[ny][nx]) {
                cnt++;
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }

    if (cnt == 7)
        return true;
    else
        return false;
}

// 조합 dfs (현재 선택, 칠공주 수, 이다솜파 수)
void dfs(int idx, int total, int cnt) {
    if (total == 7) {
        if (cnt >= 4) {
            if (bfs())
                ans++;
        }
        return;
    }

    for (int i = idx; i < MAX_N * MAX_N; i++) {
        if (isSelected[i])
            continue;

        isSelected[i] = true;
        dfs(i, total + 1, cnt + (board[i / 5][i % 5] == 'S'));
        isSelected[i] = false;
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < MAX_N; i++)
        cin >> board[i];

    dfs(0, 0, 0);

    cout << ans << "\n";

    return 0;
}