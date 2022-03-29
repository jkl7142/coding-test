/*
    15683 - ����
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define X first
#define Y second
#define MAX_N 9

using namespace std;

int n, m, ans;
int dx[4] = {1, 0, -1, 0};  // ��, ��, ��, ��
int dy[4] = {0, 1, 0, -1};
int office[MAX_N][MAX_N];   // ���ʿ� �Է¹��� ����
int spot[MAX_N][MAX_N]; // cctv�� Ȯ���� ��ġ�� üũ�س��� �迭
vector<pair<int, int>> cctv;

bool outOfBound(int x, int y) {
    return y < 0 || y >= n || x < 0 || x >= m;
}

// {x, y} ���� dir ������ ���� ���� �� ���� ��� ��ĭ�� 7�� ����
void checkWatched(int x, int y, int dir) {
    dir %= 4;
    while(true) {
        x += dx[dir];
        y += dy[dir];
        // ������ ����ų� ���� ���
        if (outOfBound(x, y) || spot[y][x] == 6)
            return;
        // cctv�� ���� ���
        if (spot[y][x] != 0)
            continue;
        
        spot[y][x] = 7;
    }
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> office[i][j];
            if (office[i][j] != 0 && office[i][j] != 6)
                cctv.push_back({j, i});
            if (office[i][j] == 0)
                ans++;
        }
    }

    // 4 ^ cctv.size() ���� 4������ �� �ڸ����� cctv�� ����
    for (int bit = 0; bit < (1 << (2 * cctv.size())); bit++) {
        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++)
                spot[r][c] = office[r][c];
        
        int quat = bit;
        for (int i = 0; i < cctv.size(); i++) {
            int dir = quat % 4;
            quat /= 4;
            int x = cctv[i].X;
            int y = cctv[i].Y;
            // tie(x, y) = cctv[i];

            if (office[y][x] == 1) {
                checkWatched(x, y, dir);
            }
            else if (office[y][x] == 2) {
                checkWatched(x, y, dir);
                checkWatched(x, y, dir + 2);
            }
            else if (office[y][x] == 3) {
                checkWatched(x, y, dir);
                checkWatched(x, y, dir + 1);
            }
            else if (office[y][x] == 4) {
                checkWatched(x, y, dir);
                checkWatched(x, y, dir + 1);
                checkWatched(x, y, dir + 2);
            }
            else {  // office[y][x] == 5
                checkWatched(x, y, dir);
                checkWatched(x, y, dir + 1);
                checkWatched(x, y, dir + 2);
                checkWatched(x, y, dir + 3);
            }
        }
        int tmp = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (spot[i][j] == 0)
                    tmp++;

        ans = min(ans, tmp);
    }

    cout << ans;

    return 0;
}