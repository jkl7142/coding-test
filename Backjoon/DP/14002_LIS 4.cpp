/*
    14002 - 가장 긴 증가하는 부분 수열 4
*/

#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

#define MAX_N 1001

int n, ans;
int seq[MAX_N];
int dp[MAX_N];
int pre[MAX_N]; // i기준으로 바로 전 Aj의 j를 기록

int main() {

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> seq[i];

    memset(dp, 1, sizeof(dp));
    int maxIdx = 1, maxDp = dp[1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (seq[j] < seq[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
        }
        if (maxDp < dp[i]) {
            maxIdx = i;
            maxDp = dp[i];
        }
    }

    stack<int> ans;
    int cur = maxIdx;
    while (cur) {
        ans.push(seq[cur]);
        cur = pre[cur];
    }

    cout << ans.size() << "\n";
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }

    return 0;
}