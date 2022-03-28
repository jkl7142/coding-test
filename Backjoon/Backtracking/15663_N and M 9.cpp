/*
    15663�� - N�� M (9)
*/

#include <iostream>
#include <algorithm>

#define MAX_N 9

using namespace std;

int n, m;
int num[MAX_N];
int arr[MAX_N];
bool visited[MAX_N];

void dfs(int idx) {
    if (idx == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = 0;
    for (int i = 0; i < n; i++) {
        // ���� ������ ������ �װ� ���� Ž���Ϸ��� ���� ������ �ߺ� ����
        if (!visited[i] && prev != num[i]) {
            visited[i] = true;
            arr[idx] = num[i];
            prev = arr[idx];
            dfs(idx + 1);
            visited[i] = false;
        }
    }
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num, num + n);

    dfs(0);

    return 0;
}