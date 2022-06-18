/*
    1520 - 내리막 길
*/

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 500;

int m, n, ans;
int map[MAX_N][MAX_N];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int dp[MAX_N][MAX_N];

int dfs(int y, int x) {
    if (y == m - 1 && x == n - 1)
        return 1;

    if (dp[y][x] != -1)
        return dp[y][x];

    dp[y][x] = 0;
    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny >= m || ny < 0 || nx >= n || nx < 0)
            continue;

        if (map[ny][nx] < map[y][x])
            dp[y][x] = dp[y][x] + dfs(ny, nx);
    }

    return dp[y][x];
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    memset(dp, -1, sizeof(dp));

    ans = dfs(0, 0);

    cout << ans;

    return 0;
}