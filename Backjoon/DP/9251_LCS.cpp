/*
*   9251번 - LCS 최장 공통 부분 수열
*   두 수열의 공통되는 가장 긴 부분 수열
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solution(string aStr, string bStr) {
    int answer = 0;
    vector<vector<int>> DP(aStr.length() + 1,
                           vector<int>(bStr.length() + 1, 0));
    
    for (int i = 1; i <= aStr.length(); i++) {
        for (int j = 1; j <= bStr.length(); j++) {
            if (aStr[i - 1] == bStr[j - 1])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
        }
    }
    
    return answer = DP[aStr.length()][bStr.length()];
}

int main() {

    string aStr, bStr;
    cin >> aStr >> bStr;

    cout << solution(aStr, bStr) << "\n";

    return 0;
}