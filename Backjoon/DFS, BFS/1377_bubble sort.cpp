/*
*   1377�� - ���� ��Ʈ
*   i�� ���� �� ������ �Ϸ�ȴٸ�, i�� ���
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(int N, vector<pair<int, int>> A) {
    sort(A.begin(), A.end());

    int maxIdx = -1;
    for (int i = 1; i <= N; i++) {
        if (maxIdx < A[i].second - i)
            maxIdx = A[i].second - i;
    }

    cout << maxIdx + 1;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> A(N + 1);
    
    for (int i = 1; i <= N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    solution(N, A);
}