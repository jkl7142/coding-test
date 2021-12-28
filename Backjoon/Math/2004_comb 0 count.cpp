/*
*   2004번 - 조합 0의 개수
*/

#include <iostream>

using namespace std;

long long factZeroCount(long long n, int num) {
    long long count = 0;
    
    for (long long i = num; i <= n; i *= num) {
        count += n / i;
    }

    return count;
}

long long solution(long long n, long long m) {
    long long answer = 0;
    long long twoCount, fiveCount;

    // comb(n, k) = n! / m! * (n - m)!
    twoCount = factZeroCount(n, 2) - factZeroCount(m, 2) - factZeroCount(n - m, 2);
    fiveCount = factZeroCount(n, 5) - factZeroCount(m, 5) - factZeroCount(n - m, 5);

    return answer = min(twoCount, fiveCount);
}

int main() {

    long long n, m;
    cin >> n >> m;

    cout << solution(n, m) << "\n";

    return 0;
}