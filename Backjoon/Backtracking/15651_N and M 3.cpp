/*
*   15651? - N? M (3)
*/

#include <iostream>
#include <vector>

using namespace std;

// ?? 1

#define MAX_N 9

int n, m;
int arr[MAX_N];

void dfs(int idx) {
    if (idx == m) {
        for (int i = 0; i < m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {  // 1 ~ n
        arr[idx] = i;
        dfs(idx + 1);
    }
}

int main() {

    cin >> n >> m;
 
    dfs(0);

    return 0;
}

// ?? 2
/* 
void dfs(int n, int m, int depth, vector<int>& answer, vector<bool>& visited) {
    
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) {
        answer[depth] = i;
        dfs(n, m, depth + 1, answer, visited);
    }
}

void solution(int n, int m) {
    vector<int> answer(n + 1, 0);
    vector<bool> visited(n + 1, false);

    dfs(n, m, 0, answer, visited);
}

int main() {

    int n, m;
    cin >> n >> m;

    solution(n, m);

    return 0;
}
*/