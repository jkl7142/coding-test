/*
*   15650번 - N과 M (2)
*/

#include <iostream>
#include <vector>

using namespace std;

// 풀이 1

#define MAX_N 9

int n, m;
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

    for (int i = cur; i <= n; i++) {  // cur ~ n까지의 수
        if (!visited[i]) {
            arr[idx] = i;
            visited[i] = true;
            dfs(idx + 1, i);    // cur를 선택한 i로 변경
            visited[i] = false;
        }
    }
}

int main() {

    cin >> n >> m;
 
    dfs(0, 1);

    return 0;
}


// 풀이 2

/* 
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
*/