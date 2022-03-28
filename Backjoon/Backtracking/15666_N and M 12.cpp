/*
    15665¹ø - N°ú M (11)
*/

#include <iostream>
#include <algorithm>

#define MAX_N 9

using namespace std;

int n, m;
int num[MAX_N];
int arr[MAX_N];

void dfs(int idx, int cur) {
    if (idx == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = -1;
    for (int i = cur; i < n; i++) {
        if (prev != num[i]) {
            arr[idx] = num[i];
            prev = arr[idx];
            dfs(idx + 1, i);
        }
    }
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    sort(num, num + n);

    dfs(0, 0);

    return 0;
}