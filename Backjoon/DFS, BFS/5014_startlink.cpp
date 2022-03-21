/*
    5014번 - 스타트링크
*/

#include <iostream>
#include <queue>

#define MAX_F 1'000'001

using namespace std;

int f, s, g, u, d;
int floor[MAX_F];
queue<int> q;

int main() {

    cin >> f >> s >> g >> u >> d;

    floor[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : {cur + u, cur - d}) {
            if (next > f || next <= 0 || floor[next] != 0)
                continue;

            floor[next] = floor[cur] + 1;
            q.push(next);
        }
    }

    if (floor[g] == 0)
        cout << "use the stairs\n";
    else
        cout << floor[g] - 1 << "\n";

    return 0;
}