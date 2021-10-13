/*
*   9641번 - 파도반 수열
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<long long> DP(101, 1);

    if (n <= 3 || (n > 4 && DP[n] != 1))
        return DP[n];

    for (int i = 4; i <= n; i++) {
        DP[i] = DP[i - 3] + DP[i - 2];
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