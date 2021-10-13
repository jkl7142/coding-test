/*
*   2579�� - ��� ������
*   ����� �� ���� �� ��ܾ� �Ǵ� �� ��ܾ� ���� �� �ִ�. ��, �� ����� �����鼭 �̾ ���� ����̳�, ���� ���� ������� ���� �� �ִ�.
*   ���ӵ� �� ���� ����� ��� ��Ƽ��� �� �ȴ�. ��, �������� ��ܿ� ���Ե��� �ʴ´�.
*   ������ ���� ����� �ݵ�� ��ƾ� �Ѵ�.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> stairs) {
    int answer = 0;
    vector<int> DP(n + 1, 0);

    DP[1] = stairs[1];
    DP[2] = stairs[1] + stairs[2];
    
    for (int i = 3; i <= n; i++) {
        DP[i] = max(DP[i - 2] + stairs[i],
                    DP[i - 3] + stairs[i - 1] + stairs[i]);
    }

    return answer = DP[n];
}

int main() {

    int n;
    cin >> n;
    vector<int> stairs(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int stair;
        cin >> stair;

        stairs[i + 1] = stair;
    }

    cout << solution(n, stairs) << "\n";

    return 0;
}