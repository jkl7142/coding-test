/*
    2696 - 중앙값 구하기
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, m;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) {
        vector<int> median;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        cin >> m;

        for (int i = 1; i <= m; i++) {
            int num;
            cin >> num;

            if (maxHeap.size() == minHeap.size())
                maxHeap.push(num);
            else
                minHeap.push(num);

            if (!maxHeap.empty() && !minHeap.empty()) {
                if (maxHeap.top() > minHeap.top()) {
                    int maxValue = maxHeap.top();
                    int minValue = minHeap.top();
                    maxHeap.pop(); minHeap.pop();
                    maxHeap.push(minValue);
                    minHeap.push(maxValue);
                }
            }

            if (i % 2 == 1) {
                median.push_back(maxHeap.top());
            }
        }

        cout << median.size() << "\n";
        for (auto n : median) {
            cout << n << " ";
        }
        cout << "\n";
    }

    return 0;
}