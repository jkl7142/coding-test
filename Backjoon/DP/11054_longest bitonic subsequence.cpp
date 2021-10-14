/*
*   11054번 - 가장 긴 바이토닉 부분 수열
*   Sk를 기준으로 S1 < S2 < Sk-1 < Sk > Sk+1 > Sn-1 > Sn
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> sequence) {
    int answer = 0;
    vector<pair<int, int>> DP(n + 1, make_pair(1, 1));

    for (int i = 1; i <= n; i++) {
        for (int l = 1; l <= i; l++) {
            if (sequence[l] < sequence[i])
                DP[i].first = max(DP[i].first, DP[l].first + 1);
        }
        
        for (int r = n; r > n - i; r--) {
            if (sequence[n - i + 1] > sequence[r])
                DP[n - i + 1].second = max(DP[n - i + 1].second, DP[r].second + 1);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        answer = max(answer, DP[i].first + DP[i].second);
    }
    
    return answer - 1;
}

int main() {

    int n;
    cin >> n;
    vector<int> sequence(1, 0);
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        sequence.push_back(a);
    }

    cout << solution(n, sequence) << "\n";

    return 0;
}