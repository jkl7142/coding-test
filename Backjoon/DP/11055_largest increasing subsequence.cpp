/*
    11055 - 가장 큰 증가 부분 수열
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_N 1001

int n, ans;
int sequence[MAX_N];
int dp[MAX_N];

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
        dp[i] = sequence[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (sequence[j] < sequence[i])
                dp[i] = max(dp[i], dp[j] + sequence[i]);
        }
        ans = max(ans, dp[i]);
    }

    cout << ans;

    return 0;
}