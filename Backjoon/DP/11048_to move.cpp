/*
    11048 - 이동하기
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 1001;

int n, m;
int map[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];

    dp[1][1] = map[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j] + map[i][j];    // 위에서 내려옴
            dp[i][j] = max(dp[i][j], dp[i][j - 1] + map[i][j]); // 왼쪽에서 옴
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + map[i][j]); // 왼쪽 위에서 옴

        }
    }

    cout << dp[n][m];

    return 0;
}