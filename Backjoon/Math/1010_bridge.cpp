/*
*   1010 - 다리 놓기
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> DP(31, vector<int>(31, 0));

int comb(int n, int r) {
    if (DP[n][r])
        return DP[n][r];

    if (n == r || r == 0)
        return DP[n][r] = 1;
    
    DP[n][r] = comb(n - 1, r - 1) + comb(n - 1, r);
    return DP[n][r];
}

int solution(pair<int, int> bridge) {
    int answer = 0;

    answer = comb(bridge.second, bridge.first);

    return answer;
}

int main() {

    int t;
    cin >> t;
    vector<pair<int, int>> bridges;

    for (int i = 0; i < t; i++) {
        int w_count, e_count;
        cin >> w_count >> e_count;

        bridges.push_back(make_pair(w_count, e_count));

        cout << solution(bridges[i]) << "\n";
    }

    return 0;
}