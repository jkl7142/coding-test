/*
    1655 - 가운데를 말해요
    중간값 문제
    1. 최대힙의 크기는 항상 최소힙의 크기보다 같거나 1만큼 더 크다.
    2. 최소힙의 모든 원소는 최대힙의 모든 원소보다 항상 크거나 같아야 한다.
      -> 최소힙의 top() 값은 항상 최대힙의 top() 값보다 크거나 같아야 한다.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        if (maxHeap.size() == minHeap.size())
            maxHeap.push(num);
        else
            minHeap.push(num);

        if (!maxHeap.empty() && !minHeap.empty()) {
            if (maxHeap.top() > minHeap.top()) {
                // swap
                int maxValue = maxHeap.top();
                int minValue = minHeap.top();
                maxHeap.pop(); minHeap.pop();
                maxHeap.push(minValue);
                minHeap.push(maxValue);
            }
        }
        cout << maxHeap.top() << "\n";
    }

    return 0;
}