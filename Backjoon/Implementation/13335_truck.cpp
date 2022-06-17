/*
    13335 - 트럭
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 1001;

int n, w, l;
int truck[MAX_N];
queue<int> q;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> l;

    for (int i = 0; i < n; i++)
        cin >> truck[i];

    int time = 0, bridge = 0;
    for (int i = 0; i < n; i++) {
        while (true) {
            // 다리에 트럭이 꽉차면 맨 앞의 트럭은 나간다
            if (q.size() == w) {
                bridge -= q.front();
                q.pop();
            }

            if (bridge + truck[i] <= l)
                break;
            
            // 다음 트럭이 들어올 수 없다면, 다리의 트럭을 앞으로 이동시킨다.
            q.push(0);
            time++;
        }

        q.push(truck[i]);
        bridge += truck[i];
        time++;
    }

    // 트럭이 들어오고 나가는 시간 + 트럭이 다리를 건너는 시간
    cout << time + w << "\n";

    return 0;
}