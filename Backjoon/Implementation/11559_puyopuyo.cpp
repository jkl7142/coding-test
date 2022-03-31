/*
    11559 - Puyo Puyo
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX_F 12
#define MAX_C 6

int ans;
bool isPuyo = true;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char field[MAX_F][MAX_C];
bool visited[MAX_F][MAX_C];

// bfs�� ���� ���� �ѿ並 ��Ʈ��
void puyo(int x, int y) {
    visited[y][x] = true;
    char color = field[y][x];
    queue<pair<int, int>> q;
    vector<pair<int, int>> tmp; // �ѿ並 ����� ���� ��ġ�� �����ϴ� tmp

    q.push({x, y});
    tmp.push_back({x, y});
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= MAX_C || ny < 0 || ny >= MAX_F)
                continue;
            
            if (visited[ny][nx] || field[ny][nx] == '.' || field[ny][nx] != color)
                continue;

            visited[ny][nx] = true;
            q.push({nx, ny});
            tmp.push_back({nx, ny});
        }
    }

    if (tmp.size() >= 4) {
        isPuyo = true;
        for (auto t : tmp) {
            field[t.second][t.first] = '.';
        }
    }
}

int main() {

    for (int i = 0; i < MAX_F; i++) {
        for (int j = 0; j < MAX_C; j++) {
            cin >> field[i][j];
        }
    }

    while (isPuyo) {    // ���� �۾��� �Ͼ�� ���� ������
        isPuyo = false;
        memset(visited, false, sizeof(visited));

        // �ѿ並 �Ʒ��� ����Ʈ��
        for (int i = 0; i < MAX_C; i++) {
            for (int j = 10; j >= 0; j--) { // �ٴ�(11) ~ �ֻ��(0)
                int tmp = j;
                while (tmp < 11 && field[tmp + 1][i] == '.') {
                    swap(field[tmp][i], field[tmp + 1][i]);
                    tmp++;
                }
            }
        }

        // �ʵ� ���� ��� �ѿ� �˻�
        for (int i = 0; i < MAX_F; i++)
            for (int j = 0; j < MAX_C; j++)
                if (!visited[i][j] && field[i][j] != '.')
                    puyo(j, i);

        if (isPuyo)
            ans++;
    }

    cout << ans;

    return 0;
}