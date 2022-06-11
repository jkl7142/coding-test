/*
    1540 - 정사각형의 개수
*/

#include <iostream>
#include <cmath>

using namespace std;

const int MAX_N = 1'000'001;

int n;
int dp[MAX_N];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // dp[4] = dp[1] + 1;
    // dp[9] = dp[4] + 4;
    for (int i = 2; i <= 1000; i++)
        dp[i * i] = dp[(i - 1) * (i - 1)] + (i - 1) * (i - 1);

    int idx = 0;
    int sqrtN = 2;

    for (int i = 5; i < MAX_N; i++) {
        // 점의 개수 i * i면 다시 우측 위부터 시작
        if (dp[i] != 0) {
            idx = 0;
            sqrtN = sqrt(i);
            continue;
        }

        // 점이 우측 대각 아래까지 도달한 경우
        if (idx == sqrtN) {
            dp[i] = dp[i - 1];
            idx = 1;
        }
        // 점이 추가되면서 사각형이 더 생기는 경우
        else {
            dp[i] = dp[i - 1] + idx;
            idx++;
        }
    }

    cout << dp[n];

    return 0;
}