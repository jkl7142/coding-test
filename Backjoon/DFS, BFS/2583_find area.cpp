/*
    2583번 - 영역 구하기
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 101

using namespace std;

int m, n, k;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int area[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];

priority_queue<int, vector<int>, greater<int>> ans;

int main() {

    cin >> m >> n >> k;

    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = y1; j < y2; j++) {
            for (int k = x1; k < x2; k++) {
                area[j][k] = 1;
            }
        }
    }

    int cnt = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (area[i][j] == 1 || visited[i][j] == 1)
            continue;
            
            int width = 1;
            queue<pair<int, int>> q;
            visited[i][j] = 1;
            q.push({i, j});
            cnt++;
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.second + dx[dir];
                    int ny = cur.first + dy[dir];

                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;

                    if (area[ny][nx] == 1 || visited[ny][nx] == 1)
                        continue;

                    q.push({ny, nx});
                    visited[ny][nx] = 1;
                    width++;
                }
            }
            ans.push(width);
        }
    }

    cout << cnt << "\n";
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }

    return 0;
}