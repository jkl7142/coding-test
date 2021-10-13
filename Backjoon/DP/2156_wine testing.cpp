/*
*   2156�� - ������ �ý�
*   1. ������ ���� �����ϸ� �� �ܿ� ����ִ� �����ָ� ��� ���ž� �ϰ�,
*   ���� �Ŀ��� ���� ��ġ�� �ٽ� ���ƾ� �Ѵ�.
*   2. �������� ���� �ִ� 3���� ��� ���� ���� ����.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> wine) {
    int answer = 0;
    vector<int> DP(n + 1, 0);

    DP[1] = wine[0];
    DP[2] = wine[0] + wine[1];

    for (int i = 3; i <= n; i++) {
        DP[i] = max(DP[i - 1], max(DP[i - 2] + wine[i - 1],
                                    DP[i - 3] + wine[i - 2] + wine[i - 1]));
    }
    
    return answer = DP[n];
}

int main() {

    int n;
    cin >> n;
    vector<int> wine;
    
    for (int i = 0; i < n; i++) {
        int ml;
        cin >> ml;

        wine.push_back(ml);
    }

    cout << solution(n, wine) << "\n";

    return 0;
}