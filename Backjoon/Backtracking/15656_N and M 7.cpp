/*
    15656¹ø - N°ú M (7)
*/

#include <iostream>
#include <algorithm>

#define MAX_N 9

using namespace std;

int n, m;
int num[MAX_N];
int arr[MAX_N];

void dfs(int idx) {
    if (idx == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        arr[idx] = num[i];
        dfs(idx + 1);
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