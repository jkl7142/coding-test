/*
*   11053번 - 최장 증가 부분 수열
*   가장 긴 증가하는 부분 수열
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> sequence) {
    int answer = 1;
    vector<int> DP(n + 1, 1);

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (sequence[j - 1] < sequence[i - 1])
                DP[i] = max(DP[i], DP[j] + 1);
        }
        answer = max(answer, DP[i]);
    }

    return answer;
}

int main() {

    int n;
    cin >> n;
    vector<int> sequence;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        sequence.push_back(num);
    }

    cout << solution(n, sequence) << "\n";

    return 0;
}