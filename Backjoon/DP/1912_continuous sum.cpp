/*
*   1912번 - 연속합
*   연속된 수의 합이 가장 큰 값
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> numbers) {
    int answer = -1000;
    vector<int> DP(n + 1, -1000);
    
    for (int i = 1; i <= n; i++) {
        DP[i] = max(numbers[i], DP[i - 1] + numbers[i]);

        answer = max(answer, DP[i]);
    }

    return answer;
}

int main() {

    int n;
    cin >> n;
    vector<int> numbers(1, 0);

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        numbers.push_back(num);
    }

    cout << solution(n, numbers) << "\n";

    return 0;
}