/*
*   1904번 - 01타일
*   N이 주어질 때, 2진 수열의 개수
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> DP(1000001, 1);

    DP[2] = 2;

    for (int i = 3; i <= n; i++) {
        DP[i] = (DP[i - 2] + DP[i - 1]) % 15746;
    }
    
    return answer = DP[n];
}

int main() {

    int n;
    cin >> n;
    
    cout << solution(n) << "\n";

    return 0;
}