/*
    9465 - 스티커
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100001

int t, n;
int sticker[2][MAX_N];
int dp[2][MAX_N];   // (i, j) 스티커는 반드시 선택했을 때 최댓값

int main() {

    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;

        for (int j = 0; j < 2; j++)
            for (int k = 0; k < n; k++)
                cin >> sticker[j][k];

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 2; k++) {
                int score = 0;

                if (j > 1)  // 바로 직전에 붙인 스티커가 j - 2 행 스티커인 경우
                    score = max(dp[0][j - 2], dp[1][j - 2]);
                    
                if (j > 0) // 바로 직전에 붙인 스티커가 j - 1 행 스티커인 경우
                    score = max(score, dp[1 - k][j - 1]);

                dp[k][j] = score + sticker[k][j];
            }
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
    }

    return 0;
}