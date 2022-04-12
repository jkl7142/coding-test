/*
    2748 - 피보나치 수 2
*/

#include <iostream>

using namespace std;

#define MAX_N 91

int N;
long long dp[MAX_N];

// 하향식
long long fibo(int n) {
    if (n == 0 || n == 1)
        return dp[n];

    if (dp[n] == 0)
        dp[n] = fibo(n - 1) + fibo(n - 2);

    return dp[n];
}

int main() {

    cin >> N;

    dp[1] = 1;
    
    cout << fibo(N);

    // 상향식
    // for (int i = 2; i <= N; i++)
    //     dp[i] = dp[i - 1] + dp[i - 2];

    // cout << dp[N];

    return 0;
}