/*
    1697�� - ���ٲ���
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
    // k ��ġ�� �湮�� �� ����
    while (visited[k] == 0) {
        int cur = q.front();
        q.pop();

        int dir[3] = {cur - 1, cur + 1, 2 * cur};
        for (int next : dir) {
            // ��� ���̸�
            if (next < 0 || next > 100000)
                continue;

            // �湮�� ���� ������
            if (visited[next] != 0)
                continue;

            // �湮�� �ð� üũ �� ���� �ܰ� ����
            visited[next] = visited[cur] + 1;
            q.push(next);
        }
    }

    cout << visited[k] - 1 << "\n";

    return 0;
}