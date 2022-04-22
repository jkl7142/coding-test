/*
    2217 - 로프
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 100'001

int n, ans;
int ropes[MAX_N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
    }

    sort(ropes, ropes + n);

    // 가장 큰 ropes[n - 1]부터 그 다음 로프 하나씩 연결할 때 최대 중량
    for (int i = 1; i <= n; i++) {
        ans = max(ans, ropes[n - i] * i);
    }

    cout << ans;

    return 0;
}