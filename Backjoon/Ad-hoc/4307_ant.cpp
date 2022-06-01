/*
    4307 - 개미
    풀이 : 방향을 바꾸는 것과 상관 없이
    마지막 개미가 막대 끝에 도달하는 최소, 최대 시간을 구해주면 된다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int t, l, n;
int ant;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) {
        cin >> l >> n;

        int minT = 0, maxT = 0;

        for (int i = 0; i < n; i++) {
            cin >> ant;

            // 가장 빠른 시간 중 마지막인 최댓값
            minT = max(minT, min(ant, l - ant));
            maxT = max(maxT, max(ant, l - ant));
        }

        cout << minT << " " << maxT << "\n";
        
    }

    return 0;
}