/*
    16985 - Maaaaaaaaaze
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_A = 1'000'000'000;

int ans = MAX_A;
int board[4][5][5][5];  // 4방향의 3차원 미로
int maze[5][5][5];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int bfs() {

    int visited[5][5][5];
    memset(visited, 0, sizeof(visited));

    if (maze[0][0][0] == 0 || maze[4][4][4] == 0)
        return -1;

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});
    visited[0][0][0] = 1;
    while (!q.empty()) {
        int curZ = q.front().first;
        int curY = q.front().second.first;
        int curX = q.front().second.second;
        q.pop();

        for (int dir = 0; dir < 6; dir++) {
            int nz = curZ + dz[dir];
            int ny = curY + dy[dir];
            int nx = curX + dx[dir];

            if (nx >= 5 || nx < 0 || ny >= 5 || ny < 0 || nz >= 5 || nz < 0)
                continue;
            if (maze[nz][ny][nx] == 0 || visited[nz][ny][nx] != 0)
                continue;

            if (nx == 4 && ny == 4 && nz == 4)
                return visited[curZ][curY][curX];
            
            visited[nz][ny][nx] = visited[curZ][curY][curX] + 1;
            q.push({nz, {ny, nx}});
        }
    }

    return -1;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                cin >> board[0][i][j][k];

        // 90도 회전한 미로 전처리
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                board[1][i][j][k] = board[0][i][4 - k][j];
        
        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                board[2][i][j][k] = board[1][i][4 - k][j];

        for (int j = 0; j < 5; j++)
            for (int k = 0; k < 5; k++)
                board[3][i][j][k] = board[2][i][4 - k][j];
    }

    int order[5] = {0, 1, 2, 3, 4};
    do {
        int ret;

        for (int tmp = 0; tmp < 1024; tmp++) {
            // dir은 중복이 가능한 모든 경우의 수, order은 모든 순열에 맞춰 미로를 구성
            int brute = tmp;
            for (int i = 0; i < 5; i++) {
                int dir = brute % 4;
                brute /= 4;

                for (int j = 0; j < 5; j++)
                    for (int k = 0; k < 5; k++)
                        maze[i][j][k] = board[dir][order[i]][j][k];
            }

            ret = bfs();

            if (ret != -1)
                ans = min(ans, ret);
        }
    } while (next_permutation(order, order + 5));

    if (ans == MAX_A)
        ans = -1;
    
    cout << ans;

    return 0;
}