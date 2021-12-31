/*
*   2164¹ø - Ä«µå2
*/

#include <iostream>
#include <queue>

using namespace std;

int solution(int n) {
    int answer = 0;
    queue<int> queue;

    for (int i = 1; i <= n; i++) {
        queue.push(i);
    }

    while (queue.size() != 1) {
        queue.pop();
        if (queue.size() != 1) {
            int data = queue.front();
            queue.push(data);
            queue.pop();
        }
    }

    return answer = queue.front();
}

int main() {

    int n;
    cin >> n;

    cout << solution(n) << "\n";

    return 0;
}