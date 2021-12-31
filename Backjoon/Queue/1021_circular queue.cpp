/*
*   1021�� - ȸ���ϴ� ť
*/

#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int solution(int n, vector<int>& location) {
    int answer = 0;
    deque<int> deque;

    for (int i = 1; i <= n; i++) {
        deque.push_back(i);
    }

    for (int i = 0; i < location.size(); i++) {
        if (deque.front() == location[i]) {
            deque.pop_front();
            continue;
        }

        auto idx = find(deque.begin(), deque.end(), location[i]);
        
        if (idx - deque.begin() < deque.end() - idx) {  // �߰����� �տ� ��ġ
            while (deque.front() != location[i]) {
                deque.push_back(deque.front());
                deque.pop_front();
                answer++;
            }
            deque.pop_front();
        }
        else {  // �߰����� �ڿ� ��ġ
            while (deque.front() != location[i]) {
                deque.push_front(deque.back());
                deque.pop_back();
                answer++;
            }
            deque.pop_front();
        }
    }

    return answer;
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> location;

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;

        location.push_back(num);
    }

    cout << solution(n, location) << "\n";

    return 0;
}