/*
*   15651¹ø - N°ú M (3)
*/

#include <iostream>
#include <vector>

using namespace std;

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