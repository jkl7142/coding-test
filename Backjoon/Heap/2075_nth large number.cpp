/*
    2075 - N번째 큰 수
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            pq.push(num);
        }

        if (i > 0) {
            for (int j = 0; j < n; j++)
                pq.pop();
        }
    }

    cout << pq.top();

    return 0;
}