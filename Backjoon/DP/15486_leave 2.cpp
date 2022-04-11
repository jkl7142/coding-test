/*
    15486 - 퇴사 2
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 1'500'001

int n, ans;
pair<int, int> jobs[MAX_N]; // { T, P }
int dp[MAX_N];  // i번째 일에 상담을 시작했을 때 얻을 수 있는 최대 수익

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> jobs[i].first >> jobs[i].second;
    }

    for (int i = n; i > 0; i--) {
        if (i + jobs[i].first <= n + 1) {
            dp[i] = max(dp[i + jobs[i].first] + jobs[i].second, dp[i + 1]);
        }
        else
            dp[i] = dp[i + 1];

        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}