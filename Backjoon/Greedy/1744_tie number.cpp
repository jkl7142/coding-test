/*
    1744 - 수 묶기
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 51

int n, num;
long long ans;
int pIdx, nIdx;
int pNum[MAX_N], nNum[MAX_N];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num == 1)
            ans++;
        else if (num > 0) {
            pNum[pIdx] = num;
            pIdx++;
        }
        else {
            nNum[nIdx] = num;
            nIdx++;
        }
    }

    sort(pNum, pNum + pIdx);
    sort(nNum, nNum + nIdx, greater<>());

    while (pIdx > 1) {
        // 맨 뒤의 수와 그 다음 수를 묶어서 더함
        ans += pNum[pIdx - 1] * pNum[pIdx - 2];
        pIdx -= 2;
    }
    if (pIdx > 0)
        ans += pNum[0];

    while (nIdx > 1) {
        // 맨 뒤의 수(음수에서 가장 작은 수)와 그 다음 수를 묶어서 더함 (음수 * 음수 = 양수)
        ans += nNum[nIdx - 1] * nNum[nIdx - 2];
        nIdx -= 2;
    }
    if (nIdx > 0)
        ans += nNum[0];

    cout << ans;

    return 0;
}