/*
    11659 - 구간 합 구하기 4
*/

#include <iostream>

using namespace std;

#define MAX_N 100'001

int n, m;
int nums[MAX_N];
int dp[MAX_N];

int prefixSum(int s, int e) {
    return dp[e] - dp[s - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        dp[i] = dp[i - 1] + nums[i];
    }

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;

        cout << prefixSum(s, e) << "\n";
    }

    return 0;
}