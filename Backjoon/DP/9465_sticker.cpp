/*
    9465 - ��ƼĿ
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100001

int t, n;
int sticker[2][MAX_N];
int dp[2][MAX_N];   // (i, j) ��ƼĿ�� �ݵ�� �������� �� �ִ�

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

                if (j > 1)  // �ٷ� ������ ���� ��ƼĿ�� j - 2 �� ��ƼĿ�� ���
                    score = max(dp[0][j - 2], dp[1][j - 2]);
                    
                if (j > 0) // �ٷ� ������ ���� ��ƼĿ�� j - 1 �� ��ƼĿ�� ���
                    score = max(score, dp[1 - k][j - 1]);

                dp[k][j] = score + sticker[k][j];
            }
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
    }

    return 0;
}