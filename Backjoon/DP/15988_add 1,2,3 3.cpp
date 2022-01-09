/*
    15988 - 1, 2, 3 ¥ı«œ±‚ 3
*/

#include <iostream>

using namespace std;

#define MAX_N 1'000'001
#define MOD 1'000'000'009

int t;
long long n;
long long dp[MAX_N];

int main() {

    cin >> t;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 0; i < t; i++) {
        cin >> n;

        for (int j = 4; j <= n; j++) {
            if (dp[j] == 0)
                dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3]) % MOD;
        }

        cout << dp[n] << "\n";
    }

    return 0;
}