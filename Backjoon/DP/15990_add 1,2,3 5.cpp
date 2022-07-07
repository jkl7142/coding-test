/*
    15990 - 1, 2, 3 더하기 5
*/

#include <iostream>

using namespace std;

const int MAX_N = 100001, MOD = 1'000'000'009;

int t, n;
long long dp[MAX_N][4];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
    for (int i = 4; i <= MAX_N; i++) {
        if (i - 1 >= 0) {
            dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
        }
        if (i - 2 >= 0) {
            dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
        }
        if (i - 3 >= 0) {
            dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
        }
    }

    while (t--) {
        cin >> n;
        cout << (dp[n][1] + dp[n][2] + dp[n][3]) % MOD << "\n";
    }

    return 0;
}