/*
    10158 - 개미
    풀이 : 공간을 2 * w, 2 * h로 확장하여 w, h보다 크면 반대 방향으로 생각한다.
*/

#include <iostream>

using namespace std;

int w, h;
int p, q;   // 초기 좌표 x, y
int t;      // 움직일 시간

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h;
    cin >> p >> q;
    cin >> t;

    p = (p + t) % (2 * w);
    q = (q + t) % (2 * h);

    // 반대 방향으로 오고 있는 경우
    if (p > w)
        p = 2 * w - p;
    if (q > h)
        q = 2 * h - q;

    cout << p << " " << q;

    return 0;
}