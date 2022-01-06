/*
*   1654번 - 랜선 자르기
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long answer = 0;

void solution(int n, long long left, long long right, vector<long long>& LANCable) {
    if (left > right)
        return;

    int lSize = LANCable.size();
    long long mid = (left + right) / 2;
    long long sum = 0;

    for (int i = 0; i < lSize; i++) {
        sum += LANCable[i] / mid;
    }

    if (sum >= n) {
        answer = max(answer, mid);
        solution(n, mid + 1, right, LANCable);
    }
    else
        solution(n, left, mid - 1, LANCable);
}

int main() {

    int k, n;
    cin >> k >> n;

    long long maxVal = 0;
    vector<long long> LANCable;

    for (int i = 0; i < k; i++) {
        long long cm;
        cin >> cm;
        maxVal = max(maxVal, cm);

        LANCable.push_back(cm);
    }

    solution(n, 1, maxVal, LANCable);

    cout << answer << "\n";

    return 0;
}