/*
*   9095번 - 1, 2, 3 더하기
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> DP(n + 1, 1);    

    DP[2] = 2;
    DP[3] = 4;
    for (int i = 4; i <= n; i++) {
        DP[i] = DP[i - 3] + DP[i - 2] + DP[i - 1];
    }

    return answer = DP[n];
}

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        cout << solution(n) << "\n";
    }

    return 0;
}