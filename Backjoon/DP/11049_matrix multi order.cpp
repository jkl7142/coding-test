/*
    11049 - 행렬 곱셈
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 501, INF = 1'000'000'000;

int n;
vector<pair<int, int>> matrix(MAX_N);
int dp[MAX_N][MAX_N];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int r, c;
        cin >> r >> c;
        matrix[i] = {r, c};
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; i + j <= n; j++) {
            dp[j][i + j] = INF;
            for (int k = j; k <= i + j; k++)
                dp[j][i + j] = min(dp[j][i + j],
                                    dp[j][k] + dp[k + 1][i + j]
                                    + matrix[j].first * matrix[k].second * matrix[i + j].second);
        }
    }

    cout << dp[1][n];

    return 0;
}