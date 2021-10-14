#include <iostream>
#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> DP(n + 1, vector<int>(m + 1, 0));

    DP[1][1] = 1;

    for (auto p : puddles) {
        DP[p[1]][p[0]] = -1;
    }

    for(int r = 1; r <= n; r++) {
        for (int c = 1; c <= m; c++) {
            if (DP[r][c] != -1) {
                if (DP[r - 1][c] != -1 && DP[r][c - 1] != -1)
                    DP[r][c] += (DP[r - 1][c] + DP[r][c - 1]) % MOD;
                else if (DP[r - 1][c] != -1)
                    DP[r][c] += DP[r - 1][c] % MOD;
                else if (DP[r][c - 1] != -1)
                    DP[r][c] += DP[r][c - 1] % MOD;
            }
        }
    }

    return answer = DP[n][m];
}

int main() {

    int m = 4;
    int n = 3;
    vector<vector<int>> puddles = {{2, 2}};

    cout << solution(m, n, puddles) << "\n";

    return 0;
}