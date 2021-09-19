/*
*   1377번 - 버블 소트
*   i번 수행 시 정렬이 완료된다면, i를 출력
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