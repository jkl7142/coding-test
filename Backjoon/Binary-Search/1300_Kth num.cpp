/*
*   1300번 - k번째 수
*/

#include <iostream>
#include <algorithm>

using namespace std;

int answer = 0;

void solution(int n, int k, int left, int right) {
    if (left > right)
        return;

    int mid = (left + right) / 2;
    int count = 0;

    for (int i = 1; i <= n; i++) {
        count += min(n, mid / i);   // j <= mid / i
    }

    if (count >= k) {
        answer = mid;
        solution(n, k, left, mid - 1);
    }
    else
        solution(n, k, mid + 1, right);
}

int main() {

    int n, k;
    cin >> n >> k;

    solution(n, k, 1, k);

    cout << answer << "\n";

    return 0;
}