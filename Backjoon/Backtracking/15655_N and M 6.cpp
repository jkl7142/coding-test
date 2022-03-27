/*
    15655¹ø - N°ú M (6)
*/

#include <iostream>
#include <algorithm>

#define MAX_N 9

using namespace std;

int n, m;
int num[MAX_N];
int arr[MAX_N];
bool visited[MAX_N];

void dfs(int idx, int cur) {
    if (idx == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = cur; i <= n; i++) {
        if (!visited[i]) {
            arr[idx] = num[i];
            visited[i] = true;
            dfs(idx + 1, i);
            visited[i] = false;
        }
    }
}

int main() {

    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    sort(num + 1, num + n + 1);

    dfs(0, 1);

    return 0;
}