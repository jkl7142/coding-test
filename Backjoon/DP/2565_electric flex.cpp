/*
*   2565�� - ������
*   ��� �������� ���� �������� �ʰ� �ϱ� ���� ���־� �ϴ� �������� �ּ� ����
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<pair<int, int>>& flex) {
    int answer = 0;
    vector<int> DP(n + 1, 1);
    
    sort(flex.begin(), flex.end());
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (flex[j - 1].second < flex[i - 1].second)
                DP[i] = max(DP[i], DP[j] + 1);
        }
        answer = max(answer, DP[i]);
    }
    
    return answer = n - answer;
}

int main() {

    int n;
    cin >> n;
    vector<pair<int, int>> flex;
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        flex.push_back(make_pair(a, b));
    }

    cout << solution(n, flex) << "\n";

    return 0;
}