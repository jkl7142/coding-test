/*
    2293 - 동전
*/

#include <iostream>

using namespace std;

#define MAX_N 101
#define MAX_K 10001

int n, k;
int coin[MAX_N];
int dp[MAX_K];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= k; j++) {
            dp[j] = dp[j] + dp[j - coin[i]];
        }
    }

    cout << dp[k];

    return 0;
}