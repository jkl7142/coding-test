/*
    1699 - 제곱수의 합
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100'001;

int n;
int dp[MAX_N];

int main() {

    cin >> n;

    for (int i = 1; i <= n; i++)
        dp[i] = i;

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[n];

    return 0;
}