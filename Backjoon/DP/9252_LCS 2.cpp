/*
*   9252번 - LCS 최장 공통 부분 수열
*   LCS 길이와 값 출력하기
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solution(string aStr, string bStr) {
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
    
    answer = DP[aStr.length()][bStr.length()];
    cout << answer << "\n";

    if (answer != 0) {
        string lcs = "";
        int k = bStr.length();

        for (int i = aStr.length(); i >= 0; i--) {
            if (DP[i][k] == 0)
                break;
            for (int j = k; j >= 0; j--) {
                if (DP[i][j] == DP[i - 1][j])
                    break;
                else if (DP[i][j] != DP[i][j - 1]) {
                    lcs += aStr[i - 1];
                    k = j - 1;
                    break;
                }
            }
        }

        reverse(lcs.begin(), lcs.end());
        cout << lcs << "\n";
    }
}

int main() {

    string aStr, bStr;
    cin >> aStr >> bStr;

    solution(aStr, bStr);

    return 0;
}