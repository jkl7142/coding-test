/*
    12852 - 1로 만들기 2
*/

#include <iostream>

using namespace std;

#define MAX_X 1'000'001

int x;
int dp[MAX_X];
int preX[MAX_X];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> x;

    dp[1] = 0;
    for (int i = 2; i <= x; i++) {
        dp[i] = dp[i - 1] + 1;
        preX[i] = i - 1;

        // 2로 나누어 떨어지면
        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            preX[i] = i / 2;
        }
        // 3으로 나누어 떨어지면
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            preX[i] = i / 3;
        }
    }

    cout << dp[x] << "\n";

    int curX = x;
    while (true) {
        cout << curX << " ";
        if (curX == 1)
            break;
        curX = preX[curX];
    }

    return 0;
}