/*
    14499 - 주사위 굴리기
*/

#include <iostream>

using namespace std;

const int MAX_N = 21;

int n, m, x, y, k;
int board[MAX_N][MAX_N];
int dice[7];    // 1 : 위, 2 : 북쪽, 3 : 동쪽, 4 : 서쪽, 5 : 남쪽, 6 : 아래
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> y >> x >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < k; i++) {
        // 1 : 동쪽, 2 : 서쪽, 3 : 북쪽, 4 : 남쪽
        int dir;
        cin >> dir;

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny >= n || ny < 0 || nx >= m || nx < 0)
            continue;

        // dir쪽으로 굴리기
        int temp = dice[1];
        if (dir == 1) {
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = temp;
        }
        if (dir == 2) {
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = temp;
        }
        if (dir == 3) {
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = temp;
        }
        if (dir == 4) {
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = temp;
        }

        cout << dice[1] << "\n";

        // 0이면 주사위 아랫면 숫자 복사
        if (board[ny][nx] == 0)
            board[ny][nx] = dice[6];
        // 0이 아니면 주사위에 보드판 숫자를 복사하고 보드판은 0
        else {
            dice[6] = board[ny][nx];
            board[ny][nx] = 0;
        }

        y = ny;
        x = nx;
    }

    return 0;
}