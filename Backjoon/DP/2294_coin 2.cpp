/*
    2294 - 동전 2
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 101;
const int MAX_K = 10001;

int n, k;
int coin[MAX_N];
int dp[MAX_K];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> coin[i];

    for (int i = 1; i <= k; i++)
        dp[i] = MAX_K;

    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= k; j++)
            dp[j] = min(dp[j], dp[j - coin[i]] + 1);
    }

    if (dp[k] == MAX_K)
        cout << -1;
    else
        cout << dp[k];

    return 0;
}