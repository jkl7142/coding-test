/*
*   1463�� - 1�� �����
*   1. X�� 3���� ������ ��������, 3���� ������.
*   2. X�� 2�� ������ ��������, 2�� ������.
*   3. 1�� ����.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> DP(n + 1, 0);    

    for (int i = 2; i <= n; i++) {
        DP[i] = DP[i - 1] + 1;
        if (i % 2 == 0)
            DP[i] = min(DP[i], DP[i / 2] + 1);
        if (i % 3 == 0)
            DP[i] = min(DP[i], DP[i / 3] + 1);
    }

    return answer = DP[n];
}

int main() {

    int n;
    cin >> n;

    cout << solution(n) << "\n";

    return 0;
}