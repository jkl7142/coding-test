/*
*   1149번 - RGB거리
*   모든 집을 빨강, 초록, 파랑으로 칠하는 비용의 최솟값을 구해라
*   1번 집의 색은 2번 집의 색과 같지 않아야 한다.
*   N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
*   i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> houses) {
    int answer = 0;
    vector<vector<int>> DP(n + 1, vector<int>(3, 0));    

    for (int i = 1; i <= n; i++) {
        DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + houses[i][0];
        DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + houses[i][1];
        DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + houses[i][2];
    }

    vector<int>::iterator minIt = min_element(DP[n].begin(), DP[n].end());

    return answer = *minIt;
}

int main() {

    int n;
    cin >> n;
    vector<vector<int>> houses(n + 1, vector<int>());

    for (int i = 1; i <= n; i++) {
        int r, g, b;
        cin >> r >> g >> b;

        houses[i].push_back(r);
        houses[i].push_back(g);
        houses[i].push_back(b);
    }

    cout << solution(n, houses) << "\n";

    return 0;
}