/*
    2302 - 극장 좌석
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 41

int n, m, ans = 1;
int vips[MAX_N];
int dp[MAX_N];    // 연속된 자리의 개수가 i개일 때 앉을 수 있는 경우의 수

int main() {

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
        cin >> vips[i];

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    for (int i = 1; i <= m; i++)
        // 각 구간 크기의 피보나치 수열을 누적해서 곱
        ans *= dp[vips[i] - vips[i - 1] - 1];
    // 마지막 vip부터 N까지의 누적 곱
    ans *= dp[n - vips[m]];

    cout << ans;

    return 0;
}