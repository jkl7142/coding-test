/*
    2193 - 이친수
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 91

int n;
long long dp[MAX_N][2];

int main() {
    
    cin >> n;

    dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1] + dp[i - 1][0];
        dp[i][1] = dp[i - 1][0];
    }

    cout << dp[n][0] + dp[n][1] << "\n";

    return 0;
}