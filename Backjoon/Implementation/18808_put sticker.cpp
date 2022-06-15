/*
    18808 - 스티커 붙이기
*/

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 41, MAX_K = 101;

int n, m, k, ans;
int board[MAX_N][MAX_N];
int sticker[MAX_N][MAX_N];
int r, c;

bool check(int sy, int sx) {
    for (int i = sy; i < sy + r; i++) {
        for (int j = sx; j < sx + c; j++) {
            if (board[i][j] == 1 && sticker[i - sy][j - sx] == 1)
                return false;
        }
    }

    return true;
}

void put(int sy, int sx) {
    for (int i = sy; i < sy + r; i++) {
        for (int j = sx; j < sx + c; j++) {
            if (sticker[i - sy][j - sx] == 1)
                board[i][j] = sticker[i - sy][j - sx];
        }
    }
}

void rotate() {
    int temp[MAX_N][MAX_N];
    
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            temp[i][j] = sticker[r - j - 1][i];
        }
    }

    memset(sticker, 0, sizeof(sticker));

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            sticker[i][j] = temp[i][j];
        }
    }
}

void swap() {
    int tmp = r;
    r = c;
    c = tmp;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        cin >> r >> c;
        for (int row = 0; row < r; row++)
            for (int col = 0; col < c; col++)
                cin >> sticker[row][col];

        bool isPut = false;

        for (int rot = 0; rot < 4; rot++) {
            if (r > n || c > m) {
                rotate();
                swap();
                continue;
            }

            for (int row = 0; row <= n - r; row++) {
                for (int col = 0; col <= m - c; col++) {
                        if (check(row, col)) {
                            put(row, col);
                            isPut = true;
                            break;
                        }
                }
                if (isPut)
                    break;
            }

            if (isPut) {
                break;
            }
            else {
                rotate();
                swap();
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans += board[i][j];

    cout << ans;

    return 0;
}