/*
*   11726�� - 2*n Ÿ�ϸ�
*   2*n ũ���� ���簢���� 1*2, 2*1 Ÿ�Ϸ� ä��� ����� ��
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> DP(n + 1, 1);    

    DP[2] = 2;
    for (int i = 3; i <= n; i++) {
        DP[i] = (DP[i - 2] + DP[i - 1]) % 10007;
    }

    return answer = DP[n];
}

int main() {

    int n;
    cin >> n;

    cout << solution(n) << "\n";


    return 0;
}