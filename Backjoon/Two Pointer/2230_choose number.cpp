/*
    2230 - 수 고르기
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 100'001;

int n, m, ans = 2'000'000'001;
int seq[MAX_N];
int sIdx, eIdx;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> seq[i];

    sort(seq, seq + n);

    for (sIdx = 0; sIdx < n; sIdx++) {
        while (eIdx < n && (seq[eIdx] - seq[sIdx]) < m)
            eIdx++;
        if (eIdx == n)
            break;
        ans = min(ans, seq[eIdx] - seq[sIdx]);
    }

    cout << ans;

    return 0;
}