/*
    6593¹ø - »ó¹ü ºôµù
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>

#define MAX_L 31

using namespace std;

struct Loc {
    int z;
    int y;
    int x;
};

int l, r, c;
char building[MAX_L][MAX_L][MAX_L];
int visited[MAX_L][MAX_L][MAX_L];
queue<Loc> q;
Loc startL, endL;
Loc dir[6] = {{0, 0, 1}, {0, 1, 0}, {0, 0, -1}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};

Loc addLoc(Loc cur, Loc move) {
    return {cur.z + move.z, cur.y + move.y, cur.x + move.x};
}

int main() {

    while (true) {
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0)
            break;

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    cin >> building[i][j][k];

                    if (building[i][j][k] == 'S')
                        startL = {i, j, k};
                    if (building[i][j][k] == 'E')
                        endL = {i, j, k};
                }
            }
        }

        memset(visited, -1, sizeof(visited));
        visited[startL.z][startL.y][startL.x] = 0;
        q.push(startL);
        while (!q.empty()) {
            Loc cur = q.front();
            q.pop();

            for (int i = 0; i < 6; i++) {
                Loc next = addLoc(cur, dir[i]);

                if (next.z < 0 || next.z >= l || next.y < 0
                    || next.y >= r || next.x < 0 || next.x >= c)
                    continue;
                
                if (building[next.z][next.y][next.x] == '#'
                    || visited[next.z][next.y][next.x] != -1)
                    continue;

                visited[next.z][next.y][next.x]
                = visited[cur.z][cur.y][cur.x] + 1;
                q.push({next});
            }
        }

        if (visited[endL.z][endL.y][endL.x] != -1) {
            cout << "Escaped in " << visited[endL.z][endL.y][endL.x]
                << " minute(s).\n";
        }
        else {
            cout << "Trapped!\n";
        }

        while (!q.empty())
            q.pop();
    }

    return 0;
}