/*
    1965 - 상자넣기
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1001;

int n, ans;
int box[MAX_N];
int dp[MAX_N];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> box[i];

    for (int i = 1; i <= n; i++) {

        dp[i] = 1;

        for (int j = 1; j < i; j++) {
            if (box[j] < box[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}