/*
    2133 - 타일 채우기
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 31;

int n;
int dp[MAX_N];

int main() {

    cin >> n;

    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    for (int i = 4; i <= n; i += 2) {
        dp[i] = 3 * dp[i - 2];

        for (int j = i - 4; j >= 0; j -= 2)
            dp[i] = dp[i] + 2 * dp[j];
    }

    cout << dp[n];

    return 0;
}