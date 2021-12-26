/*
*   11051번 - 이항 계수 2
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> DP(1001, vector<int>(1001, 1));

int combination(int n, int k) {

    if (DP[n][k] != 1)
        return DP[n][k];

    if (n == 1 || k == 0 || k == n)
        return DP[n][k];

    return DP[n][k] = (combination(n - 1, k - 1) + combination(n - 1, k)) % 10007;
}

int main() {

    int n, k;
    cin >> n >> k;

    cout << combination(n, k) << "\n";

    return 0;
}