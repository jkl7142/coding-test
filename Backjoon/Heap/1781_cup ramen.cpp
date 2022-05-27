/*
    1781 - 컵라면
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, ans;
vector<pair<int, int>> question;    // {데드라인, 컵라면 수}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int deadline, cupCnt;
        cin >> deadline >> cupCnt;

        question.push_back({deadline, cupCnt});
    }

    sort(question.begin(), question.end());

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        if (pq.size() < question[i].first)
            pq.push(question[i].second);
        else if (pq.top() < question[i].second) {
            pq.pop();
            pq.push(question[i].second);
        }
    }

    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans;

    return 0;
}