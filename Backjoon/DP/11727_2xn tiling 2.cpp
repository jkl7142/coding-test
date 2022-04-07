/*
    11727 - 2xn ≈∏¿œ∏µ 2
*/

#include <iostream>

using namespace std;

#define MAX_N 1'001
#define MOD 10'007

int n;
int dp[MAX_N];

int main() {

    cin >> n;

    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % MOD;
    }

    cout << dp[n] << "\n";

    return 0;
}