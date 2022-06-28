/*
    17070 - 파이프 옮기기
*/

#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = 17;

struct pipe {
    int y;
    int x;
    int dir;
};

int board[MAX_N][MAX_N];
int n, ans;
int dy[3] = {0, 1, 1};
int dx[3] = {1, 1, 0};
queue<pipe> q;

void move(pipe p, int i) {
    pipe next = {p.y + dy[i], p.x + dx[i], i};

    if (next.y >= n || next.y < 0 || next.x >= n || next.x < 0)
        return;

    if (board[next.y][next.x] == 0) {
        if (i == 1) {   // 대각선이면 위, 왼쪽 체크
            if (board[next.y - 1][next.x] == 1 || board[next.y][next.x - 1] == 1)
                return;
        }

        q.push(next);
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    q.push({0, 1, 0});
    while (!q.empty()) {
        pipe cur = q.front();
        q.pop();

        if (cur.y == n - 1 && cur.x == n - 1)
            ans++;

        if (cur.dir == 0) {  // 가로
            for (int i = 0; i < 2; i++)
                move(cur, i);
        }
        else if (cur.dir == 1) { // 대각선
            for (int i = 0; i < 3; i++)
                move(cur, i);
        }
        else {  // 세로
            for (int i = 1; i < 3; i++)
                move(cur, i);
        }
    }

    cout << ans;

    return 0;
}