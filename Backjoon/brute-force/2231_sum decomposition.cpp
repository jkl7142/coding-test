/*
*   2231번 - 분해합
*/

#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = 1; i < n; i++) {
        int sum = i;
        int temp = i;

        while (temp > 10) {
            sum += temp % 10;
            temp /= 10;
        }
        sum += temp;

        if (sum == n) {
            answer = i;
            return answer;
        }
    }

    return answer;
}

int main() {

    int n;
    cin >> n;

    cout << solution(n) << "\n";

    return 0;
}