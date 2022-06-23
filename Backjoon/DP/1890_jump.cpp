/*
    1890 - 점프
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 101;

int n;
int board[MAX_N][MAX_N];
long long dp[MAX_N][MAX_N];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    dp[0][0] = 1;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (board[r][c] == 0 || dp[r][c] == 0)
                continue;

            int moveRight = c + board[r][c];
            int moveDown = r + board[r][c];

            if (moveRight < n)
                dp[r][moveRight] += dp[r][c];
            if (moveDown < n)
                dp[moveDown][c] += dp[r][c];
        }
    }

    cout << dp[n - 1][n - 1];

    return 0;
}