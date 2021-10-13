/*
*   10844�� - ���� ��� ��
*   ��� �� : ������ ��� �ڸ��� ���̰� 1
*   N�� �־��� ��, ���̰� N�� ��� �� ���ϱ�
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000000

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<vector<int>> DP(n + 1, vector<int>(10, 1));

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0)
                DP[i][j] = DP[i - 1][j + 1] % MOD;
            else if (j == 9)
                DP[i][j] = DP[i - 1][j - 1] % MOD;
            else
                DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % MOD;
        }
    }

    for (int i = 1; i < 10; i++) {
        answer = (answer + DP[n][i]) % MOD;
    }
    
    return answer;
}

int main() {

    int n;
    cin >> n;
    
    cout << solution(n) << "\n";

    return 0;
}