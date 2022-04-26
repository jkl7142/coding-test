/*
    11000 - 강의실 배정
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 풀이 1. 우선순위 큐

int n, ans;
vector<pair<int, int>> Class;
priority_queue<int, vector<int>, greater<>> pq;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        Class.push_back({s, t});
    }

    sort(Class.begin(), Class.end());

    pq.push(0);

    for (int i = 0; i < n; i++) {
        int curTime = pq.top();
        pq.pop();
        pair<int, int> cur = Class[i];
        
        if (cur.first < curTime)
            pq.push(curTime);
        pq.push(cur.second);
    }

    cout << pq.size();

    return 0;
}

// 풀이 2. greedy
/*
int n, ans;
vector<pair<int, int>> Class; // 2n : (s, 1), (t, -1)
int cur;    // 현재 열려있는 강의실의 개수
int curTime;   // 현재 시간
int idx;    // 현재 Class의 idx

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        Class.push_back({s, 1});
        Class.push_back({t, -1});
    }

    sort(Class.begin(), Class.end());

    curTime = Class[0].first;
    while (true) {
        while (idx < 2 * n && Class[idx].first == curTime) {
            // s면 1을 더함, t면 1을 뺌
            cur += Class[idx].second;
            idx++;
        }

        ans = max(ans, cur);
        if (idx == 2 * n)
            break;
        
        curTime = Class[idx].first;
    }

    cout << ans;

    return 0;
}
*/