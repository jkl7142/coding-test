/*
    4883 - 삼각 그래프
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100'001

int n, ans;
int graph[MAX_N][3];
int dp[MAX_N][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int t = 1; ; t++) {
        cin >> n;

        if (n == 0)
            break;

        for (int i = 0; i < n; i++) {
            cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
        }

        dp[0][0] = 1001;
        dp[0][1] = graph[0][1];
        dp[0][2] = graph[0][1] + graph[0][2];

        for (int i = 1; i < n; i++) {
            dp[i][0] = graph[i][0] + min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = graph[i][1] + min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i][0]});
            dp[i][2] = graph[i][2] + min({dp[i - 1][1], dp[i - 1][2], dp[i][1]});
        }

        cout << t << ". " << dp[n - 1][1] << "\n";
    }

    return 0;
}