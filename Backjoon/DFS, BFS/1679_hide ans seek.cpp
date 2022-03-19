/*
    1697번 - 숨바꼭질
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 100'001

using namespace std;

int n, k;
int visited[MAX_N];
queue<int> q;

int main() {

    cin >> n >> k;

    visited[n] = 1;
    q.push(n);
    // k 위치를 방문할 때 까지
    while (visited[k] == 0) {
        int cur = q.front();
        q.pop();

        int dir[3] = {cur - 1, cur + 1, 2 * cur};
        for (int next : dir) {
            // 경로 밖이면
            if (next < 0 || next > 100000)
                continue;

            // 방문한 적이 있으면
            if (visited[next] != 0)
                continue;

            // 방문한 시간 체크 후 다음 단계 진행
            visited[next] = visited[cur] + 1;
            q.push(next);
        }
    }

    cout << visited[k] - 1 << "\n";

    return 0;
}