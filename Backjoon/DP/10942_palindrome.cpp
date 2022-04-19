/*
    10942 - 팰린드롬?
*/

#include <iostream>

using namespace std;

#define MAX_N 2001

int n, m;
int num[MAX_N];
int dp[MAX_N][MAX_N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];

    // 숫자가 1개거나 연속된 같은 숫자면 팰린드롬
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
        if (num[i - 1] == num[i])
            dp[i - 1][i] = 1;
    }

    // s ~ e까지가 팰린드롬이려면 s + 1 ~ e - 1까지도 팰린드롬 이어야 한다.
    for (int gap = 2; gap < n; gap++) {
        for (int i = 1; i <= n - gap; i++) {
            int s = i, e = i + gap;
            
            if (num[s] == num[e] && dp[s + 1][e - 1])
                dp[s][e] = 1;
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }

    return 0;
}