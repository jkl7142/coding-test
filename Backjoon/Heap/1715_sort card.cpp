/*
    1715 - 카즈 정렬하기
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 100'001;

int n, ans;
priority_queue<int, vector<int>, greater<int>> pq;

int main () {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int card;
        cin >> card;
        pq.push(card);
    }

    while (pq.size() >= 2) {
        int aPack = pq.top();
        pq.pop();
        int bPack = pq.top();
        pq.pop();

        ans += aPack + bPack;
        pq.push(aPack + bPack);
    }

    cout << ans;

    return 0;
}