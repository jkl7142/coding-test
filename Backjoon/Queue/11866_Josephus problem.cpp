/*
*   11866번 - 요세푸스 문제 0
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printAns(vector<int> answer) {
    cout << "<";
    for (int i = 0; i < answer.size(); i++) {
        if (i == answer.size() - 1)
            cout << answer[i] << ">";
        else
            cout << answer[i] << ", ";
    }
}

void solution(int n, int k) {
    vector<int> answer;
    queue<int> queue;

    for (int i = 1; i <= n; i++) {
        queue.push(i);
    }

    while (!queue.empty()) {
        for (int i = 1; i < k; i++) {
            queue.push(queue.front());
            queue.pop();
        }

        answer.push_back(queue.front());
        queue.pop();
    }

    printAns(answer);
}

int main() {

    int n, k;
    cin >> n >> k;

    solution(n, k);

    return 0;
}