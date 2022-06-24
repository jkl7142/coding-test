/*
    9655 - 돌 게임
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 1001;

int n;
int dp[MAX_N];  // 돌의 개수에 대한 게임 횟수

int main() {

    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
        dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);

    if (dp[n] % 2 == 1)
        cout << "SK";
    else
        cout << "CY";

    return 0;
}