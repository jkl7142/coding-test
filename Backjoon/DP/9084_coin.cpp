/*
    9084 - 동전
*/

#include <iostream>
#include <cstring>

using namespace std;

#define MAX_N 21
#define MAX_M 10001

int t, n, m;
int coin[MAX_N];
int dp[MAX_M];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;

        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++)
            cin >> coin[i];

        cin >> m;

        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = coin[i]; j <= m; j++) {
                dp[j] += dp[j - coin[i]];
            }
        }

        cout << dp[m] << "\n";
    }

    return 0;
}