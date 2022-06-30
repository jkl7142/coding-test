/*
    1915 - 가장 큰 정사각형
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_N = 1001;

int n, m, ans;
int board[MAX_N][MAX_N];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            board[i][j + 1] = str[j] - '0';
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (board[i][j] != 0) {
                board[i][j] = min(board[i - 1][j], min(board[i][j - 1], board[i - 1][j - 1])) + 1;
                ans = max(ans, board[i][j]);
            }
        }
    }

    cout << ans * ans << "\n";

    return 0;
}