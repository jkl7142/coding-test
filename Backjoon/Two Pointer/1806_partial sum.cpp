/*
*   1806번 - 부분합
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int s, vector<int> sequence) {
    int answer = n + 1;

    int sum = 0, start = 0, end = 0;

    while (start <= end) {
        if (sum >= s) {
            answer = min(answer, end - start);
            sum -= sequence[start++];
        }
        else {
            if (end == n)
                break;
            sum += sequence[end++];
        }
    }

    if (answer == n + 1)
        answer = 0;

    return answer;
}

int main() {

    int n, s;
    cin >> n >> s;
    vector<int> sequence;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        sequence.push_back(num);
    }

    cout << solution(n, s, sequence) << "\n";

    return 0;
}