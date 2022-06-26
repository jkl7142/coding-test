/*
    11066 - 파일 합치기
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 501;
const int INF = 1'000'000'000;

int t, n;
int file[MAX_N];
int sumFiles[MAX_N];    // 1 ~ n번째 파일까지 크기의 합
int dp[MAX_N][MAX_N];   // i ~ j번째 파일들을 합치는 데 필요한 최소비용

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> file[i];
            sumFiles[i] = sumFiles[i - 1] + file[i];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n - i; j++) {

                dp[j][j + i] = INF;
                for (int k = j; k < j + i; k++)
                    dp[j][j + i] = min(dp[j][j + i],
                                    dp[j][k] + dp[k + 1][j + i] + sumFiles[j + i] - sumFiles[j - 1]);
            }
        }

        cout << dp[1][n] << "\n";
    }

    return 0;
}