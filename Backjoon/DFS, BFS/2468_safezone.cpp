/*
    2468번 - 안전 영역
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 101

using namespace std;

int n, ans, maxH;
int zone[MAX_N][MAX_N];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int h;
            cin >> h;
            zone[i][j] = h;
            
            if (h > maxH)
                maxH = h;
        }
    }

    for (int rain = 0; rain <= maxH; rain++) {
        int visited[MAX_N][MAX_N] = {0, };
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (zone[i][j] <= rain || visited[i][j] != 0)
                    continue;

                visited[i][j] = 1;
                q.push({j, i});
                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;

                        if (zone[ny][nx] <= rain || visited[ny][nx] != 0)
                            continue;

                        visited[ny][nx] = 1;
                        q.push({nx, ny});
                    }
                }

                cnt++;
            }
        }

        ans = max(ans, cnt);
    }

    cout << ans;

    return 0;
}