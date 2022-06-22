/*
    1309 - 동물원
*/

#include <iostream>

using namespace std;

const int MAX_N = 100'001;
const int MOD = 9901;

int n;
int dp[MAX_N][3];   // 사자를 왼쪽에 놓는 경우, 사자를 오른쪽에 놓는 경우, 사자를 놓지 않는 경우

int main() {

    cin >> n;

    for (int i = 0; i < 3; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
    }

    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;

    return 0;
}