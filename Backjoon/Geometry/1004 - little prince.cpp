/*
    1004 - 어린 왕자
*/
#include <iostream>

using namespace std;

int t, n, ans;
int x1, y1, x2, y2;
int cx, cy, cr;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++) {
        ans = 0;

        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> cx >> cy >> cr;

            // 출발점과 c사이의 거리
            int dist1 = (x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy);
            // 도착점과 c사이의 거리
            int dist2 = (x2 - cx) * (x2 - cx) + (y2 - cy) * (y2 - cy);
            int powr = cr * cr;

            // 같은 행성계에 속한 경우
            if (dist1 < powr && dist2 < powr)
                continue;
            // 한 점만 하나의 행성계에 속한 경우
            else if (dist1 < powr || dist2 < powr)
                ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}