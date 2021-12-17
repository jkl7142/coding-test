/*
*   15650¹ø - N°ú M (2)
*/

#include <iostream>
#include <vector>

using namespace std;

void dfs(int n, int m, int current, int depth, vector<int>& answer, vector<bool>& visited) {
    
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = current; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            answer[depth] = i;
            dfs(n, m, i + 1, depth + 1, answer, visited);
            visited[i] = false;
        }
    }
}

void solution(int n, int m) {
    vector<int> answer(n + 1, 0);
    vector<bool> visited(n + 1, false);

    dfs(n, m, 1, 0, answer, visited);
}

int main() {

    int n, m;
    cin >> n >> m;

    solution(n, m);

    return 0;
}