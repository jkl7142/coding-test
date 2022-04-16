/*
    11052 - 카드 구매하기
*/

#include <iostream>

using namespace std;

#define MAX_N 1001

int n;
int dp[MAX_N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> dp[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++)
            dp[i] = max(dp[i], dp[i - j] + dp[j]);
    }

    cout << dp[n];

    return 0;
}