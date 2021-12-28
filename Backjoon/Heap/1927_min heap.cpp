/*
*   1927锅 - 弥家 赛
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solution(vector<int> calculate) {
    priority_queue<int, vector<int>, greater<int>> pq; // 弥家 赛

    for (auto x : calculate) {
        if (x > 0) {
            pq.push(x);
        }
        else if (pq.empty()) {
            cout << x << "\n";
        }
        else {
            cout << pq.top() << "\n";
            pq.pop();
        }
    }
}

int main() {

    int n;
    cin >> n;
    vector<int> calculate;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        calculate.push_back(x);
    }

    solution(calculate);

    return 0;
}