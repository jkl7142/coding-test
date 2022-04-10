/*
    14501 - Επ»η
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 16

int n, ans;
pair<int, int> jobs[MAX_N]; // { T, P }
int dp[MAX_N];

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> jobs[i].first >> jobs[i].second;
    }

    for (int i = 0; i <= n; i++) {
        dp[i] = max(dp[i], dp[i - 1]);
        if (i + jobs[i].first <= n + 1) {
            dp[i + jobs[i].first] = max(dp[i + jobs[i].first]
                                        , dp[i] + jobs[i].second);
        }
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}