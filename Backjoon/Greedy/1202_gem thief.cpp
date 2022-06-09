/*
    1202 - 보석 도둑
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 300'001;

int n, k;
pair<int, int> gem[MAX_N];
int bag[MAX_N];
long long ans;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> gem[i].first >> gem[i].second;
    }

    for (int i = 0; i < k; i++) {
        cin >> bag[i];
    }

    priority_queue<int> pq;

    // 보석 무게를 기준으로 오름차순 정렬
    sort(gem, gem + n);
    // 무게를 기준으로 오름차순 정렬
    sort(bag, bag + k);

    int idx = 0;
    for (int i = 0; i < k; i++) {
        // 보석이 가방 무게보다 작다면 푸시
        while (idx < n && gem[idx].first <= bag[i]) {
            pq.push(gem[idx].second);
            idx++;
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;

    return 0;
}