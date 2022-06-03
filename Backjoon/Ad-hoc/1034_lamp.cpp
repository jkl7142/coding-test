/*
    1034 - 램프
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_N = 51;

int n, m, k, ans;
string lamp[MAX_N];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> lamp[i];
    }

    cin >> k;

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (lamp[i][j] == '0')
                cnt++;
        }

        int onCnt = 0;

        // 꺼져있는 램프가 k개 이하이고, 둘다 짝수거나 홀수이면 켜져있는 행 가능
        if (cnt <= k && cnt % 2 == k % 2) {
            for (int j = 0; j < n; j++) {
                if (lamp[i] == lamp[j])
                    onCnt++;
            }
        }

        ans = max(ans, onCnt);
    }

    cout << ans;

    return 0;
}