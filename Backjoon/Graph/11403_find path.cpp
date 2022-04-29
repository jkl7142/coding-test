/*
    11403 - 경로 찾기
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 101

int n;
int graph[MAX_N][MAX_N];

void floyd(void) {
    // k를 거쳐갈 수 있으면 경로가 있음
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (graph[i][k] && graph[k][j])
                    graph[i][j] = 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    
    floyd();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << graph[i][j] << " ";
        cout << "\n";
    }

    return 0;
}