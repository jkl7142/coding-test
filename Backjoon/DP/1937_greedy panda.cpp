/*
    1937 - 욕심쟁이 판다
*/

#include <iostream>
#include <iostream>

using namespace std;

const int MAX_N = 501;

int n, ans;
int bamboo[MAX_N][MAX_N];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int dp[MAX_N][MAX_N];

int dfs(int y, int x) {
    if (dp[y][x] != 0)
        return dp[y][x];

    dp[y][x] = 1;
    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny >= n || ny < 0 || nx >= n || nx < 0)
            continue;

        if (bamboo[y][x] < bamboo[ny][nx]) {
            dp[y][x] = max(dp[y][x], dfs(ny, nx) + 1);
        }
    }

    return dp[y][x];
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> bamboo[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = max(ans, dfs(i, j));

    cout << ans;

    return 0;
}