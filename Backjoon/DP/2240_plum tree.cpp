/*
    2240 - 자두나무
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_T 1001
#define MAX_W 31

int t, w, ans;
int drop[MAX_T];
int dp[MAX_T][MAX_W][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> w;

    for (int i = 1; i <= t; i++)
        cin >> drop[i];

    for (int i = 0; i <= w; i++) {
        for (int j = 1; j <= t; j++) {
            if (i == 0)
                dp[j][i][1] = dp[j - 1][i][1] + (drop[j] == 1);
            else {
                // 1번 나무에서 받는 경우
                dp[j][i][1] = max(dp[j - 1][i][1] + (drop[j] == 1), dp[j - 1][i - 1][2] + (drop[j] == 1));
                // 2번 나무에서 받는 경우
                dp[j][i][2] = max(dp[j - 1][i][2] + (drop[j] == 2), dp[j - 1][i - 1][1] + (drop[j] == 2));
            }
            
            ans = max(ans, max(dp[j][i][1], dp[j][i][2]));
        }
    }

    cout << ans;

    return 0;
}