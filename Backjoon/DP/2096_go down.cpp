/*
    2096 - 내려가기
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 100'001;

int n;
int board[3], temp[3];
int maxDP[3], minDP[3];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < 3; i++) {
        cin >> maxDP[i];
        minDP[i] = maxDP[i];
    }

    for (int i = 1; i < n; i++) {
        // 최대 점수
        for (int j = 0; j < 3; j++) {
            cin >> board[j];
            temp[j] = maxDP[j];
        }
        
        maxDP[0] = max(temp[0], temp[1]) + board[0];
        maxDP[1] = max(temp[0], max(temp[1], temp[2])) + board[1];
        maxDP[2] = max(temp[1], temp[2]) + board[2];

        // 최소 점수
        for (int j = 0; j < 3; j++)
            temp[j] = minDP[j];

        minDP[0] = min(temp[0], temp[1]) + board[0];
        minDP[1] = min(temp[0], min(temp[1], temp[2])) + board[1];
        minDP[2] = min(temp[1], temp[2]) + board[2];
    }

    cout << max(maxDP[0], max(maxDP[1], maxDP[2])) << " ";
    cout << min(minDP[0], min(minDP[1], minDP[2]));

    return 0;
}