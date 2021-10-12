/*
*   1149�� - RGB�Ÿ�
*   ��� ���� ����, �ʷ�, �Ķ����� ĥ�ϴ� ����� �ּڰ��� ���ض�
*   1�� ���� ���� 2�� ���� ���� ���� �ʾƾ� �Ѵ�.
*   N�� ���� ���� N-1�� ���� ���� ���� �ʾƾ� �Ѵ�.
*   i(2 �� i �� N-1)�� ���� ���� i-1��, i+1�� ���� ���� ���� �ʾƾ� �Ѵ�.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> houses) {
    int answer = 0;
    vector<vector<int>> DP(n + 1, vector<int>(3, 0));    

    for (int i = 1; i <= n; i++) {
        DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + houses[i][0];
        DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + houses[i][1];
        DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + houses[i][2];
    }

    vector<int>::iterator minIt = min_element(DP[n].begin(), DP[n].end());

    return answer = *minIt;
}

int main() {

    int n;
    cin >> n;
    vector<vector<int>> houses(n + 1, vector<int>());

    for (int i = 1; i <= n; i++) {
        int r, g, b;
        cin >> r >> g >> b;

        houses[i].push_back(r);
        houses[i].push_back(g);
        houses[i].push_back(b);
    }

    cout << solution(n, houses) << "\n";

    return 0;
}