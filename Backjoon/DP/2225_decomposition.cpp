/*
    2225 - 합분해
*/

#include <iostream>

using namespace std;

const int MAX_N = 201;
const int MOD = 1'000'000'000;

int n, k;
long long dp[MAX_N][MAX_N];

int main() {

    cin >> n >> k;

    for (int i = 0; i <= n; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            for (int l = 0; l <= j; l++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][l]) % MOD;
            }
        }
    }

    cout << dp[k][n];

    return 0;
}