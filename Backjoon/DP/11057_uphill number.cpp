/*
    11057 - 오르막 수
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

#define MAX_N 1001
#define MOD 10007

int n;
vector<vector<long long>> dp(MAX_N, vector<long long>(10));

int main() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;

        for (int j = 1; j < 10; j++)
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
    }

    // begin ~ end 전까지 sum (초기값은 0)
    cout << accumulate(dp[n].begin(), dp[n].end(), 0) % MOD;

    return 0;
}