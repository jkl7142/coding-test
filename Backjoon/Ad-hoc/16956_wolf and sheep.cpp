/*
    16956 - 늑대와 양
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 501;

int r, c;
char farm[MAX_N][MAX_N];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
queue<pair<int, int>> wolf;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> farm[i][j];

            if (farm[i][j] == 'W')
                wolf.push({i, j});
        }
    }

    while (!wolf.empty()) {
        pair<int, int> cur = wolf.front();
        wolf.pop();

        for (int i = 0; i < 4; i++) {
            pair<int, int> next = {cur.first + dy[i], cur.second + dx[i]};

            if (next.first < 0 || next.first >= r || next.second < 0 || next.second >= c)
                continue;

            if (farm[next.first][next.second] == 'S') {
                cout << 0 << "\n";
                return 0;
            }

            if (farm[next.first][next.second] == '.')
                farm[next.first][next.second] = 'D';
        }
    }

    cout << 1 << "\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << farm[i][j];
        }
        cout << "\n";
    }

    return 0;
}