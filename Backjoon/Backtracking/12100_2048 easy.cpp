/*
    12100 - 2048 (easy)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 21;

int n, maxBlock;
vector<vector<int>> board(MAX_N, vector<int>(MAX_N));
bool visited[MAX_N][MAX_N];

vector<vector<int>> upMove(vector<vector<int>> tmp) {
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (tmp[j][i] == 0)
                continue;

            for (int k = j - 1; k >= 0; k--) {
                // 1. 병합
                if (tmp[k][i] == tmp[k + 1][i] && !visited[k][i]) {
                    tmp[k][i] = tmp[k][i] * 2;
                    tmp[k + 1][i] = 0;
                    visited[k][i] = true;
                    break;
                }
                // 2. 이동
                else if (tmp[k][i] == 0) {
                    tmp[k][i] = tmp[k + 1][i];
                    tmp[k + 1][i] = 0;
                }
                else
                    break;
            }
        }
    }

    return tmp;
}

vector<vector<int>> rightMove(vector<vector<int>> tmp) {
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = n - 2; j >= 0; j--) {
            if (tmp[i][j] == 0)
                continue;

            for (int k = j + 1; k < n; k++) {
                // 1. 병합
                if (tmp[i][k] == tmp[i][k - 1] && !visited[i][k]) {
                    tmp[i][k] = tmp[i][k] * 2;
                    tmp[i][k - 1] = 0;
                    visited[i][k] = true;
                    break;
                }
                // 2. 이동
                else if (tmp[i][k] == 0) {
                    tmp[i][k] = tmp[i][k - 1];
                    tmp[i][k - 1] = 0;
                }
                else
                    break;
            }
        }
    }

    return tmp;
}

vector<vector<int>> downMove(vector<vector<int>> tmp) {
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = n - 2; j >= 0; j--) {
            if (tmp[j][i] == 0)
                continue;

            for (int k = j + 1; k < n; k++) {
                // 1. 병합
                if (tmp[k][i] == tmp[k - 1][i] && !visited[k][i]) {
                    tmp[k][i] = tmp[k][i] * 2;
                    tmp[k - 1][i] = 0;
                    visited[k][i] = true;
                    break;
                }
                // 2. 이동
                else if (tmp[k][i] == 0) {
                    tmp[k][i] = tmp[k - 1][i];
                    tmp[k - 1][i] = 0;
                }
                else
                    break;
            }
        }
    }

    return tmp;
}

vector<vector<int>> leftMove(vector<vector<int>> tmp) {
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (tmp[i][j] == 0)
                continue;

            for (int k = j - 1; k >= 0; k--) {
                // 1. 병합
                if (tmp[i][k] == tmp[i][k + 1] && !visited[i][k]) {
                    tmp[i][k] = tmp[i][k] * 2;
                    tmp[i][k + 1] = 0;
                    visited[i][k] = true;
                    break;
                }
                // 2. 이동
                else if (tmp[i][k] == 0) {
                    tmp[i][k] = tmp[i][k + 1];
                    tmp[i][k + 1] = 0;
                }
                else
                    break;
            }
        }
    }

    return tmp;
}

void dfs(int cnt, vector<vector<int>> tmp) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            maxBlock = max(maxBlock, tmp[i][j]);

    if (cnt == 5)
        return;

    dfs(cnt + 1, upMove(tmp));
    dfs(cnt + 1, rightMove(tmp));
    dfs(cnt + 1, downMove(tmp));
    dfs(cnt + 1, leftMove(tmp));
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    dfs(0, board);

    cout << maxBlock << "\n";

    return 0;
}