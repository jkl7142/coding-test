/*
*   11050번 - 이항 계수 1
*/

#include <iostream>

using namespace std;

int fact(int n) {
    if (n == 1 || n == 0)
        return 1;

    return n * fact(n - 1);
}

int solution(int n, int k) {
    int answer = 0;

    // 이항 계수 n! / k!(n - k)!
    answer = fact(n) / (fact(k) * fact(n - k));

    return answer;
}

int main() {

    int n, k;
    cin >> n >> k;

    cout << solution(n, k) << "\n";

    return 0;
}