/*
*   2003번 - 수 들의 합 2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> sequence) {
    int answer = 0;

    int sum = 0, start = 0, end = 0;

    while (start <= end && end <= n) {
        if (sum >= m) {
            if (sum == m) {
                answer++;
            }

            sum -= sequence[start++];
        }
        else {
            sum += sequence[end++];
        }
    }

    return answer;
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<int> sequence;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        sequence.push_back(num);
    }

    cout << solution(n, m, sequence) << "\n";

    return 0;
}