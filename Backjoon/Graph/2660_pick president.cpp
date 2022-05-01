/*
    2660 - 회장뽑기
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 51
#define INF 1'000'000

int n;
int Friend, pScore = INF, cCnt;
int graph[MAX_N][MAX_N];
int cScore[MAX_N];

void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
                graph[i][j] = INF;

    while (true) {
        int a, b;
        cin >> a >> b;

        if (a == -1 && b == -1)
            break;

        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    floyd();

    for (int i = 1; i <= n; i++) {
        Friend = 0;
        for (int j = 1; j <= n; j++) {
            Friend = max(Friend, graph[i][j]);
        }

        cScore[i] = Friend;

        if (pScore == INF || pScore > cScore[i])
            pScore = cScore[i];
    }

    cout << pScore << " ";

    for (int i = 1; i <= n; i++) {
        if (pScore == cScore[i])
            cCnt++;
    }

    cout << cCnt << "\n";
    
    for (int i = 1; i <= n; i++) {
        if (pScore == cScore[i])
            cout << i << " ";
    }

    return 0;
}