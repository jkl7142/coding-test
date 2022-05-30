/*
    1644 - 소수의 연속합
*/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_N = 4'000'002;

int n, ans;
bool isPrime[MAX_N];
vector<int> prime;

// 에라토스테네스의 체
void findPrime() {
    for (int i = 2; i * i <= n; i++) {
        if (!isPrime[i])
            continue;

        for (int j = i * i; j <= n; j += i)
            isPrime[j] = false;
    }

    // 소수 배열 생성
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            prime.push_back(i);
        }
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    memset(isPrime, true, sizeof(isPrime));

    findPrime();

    int sIdx = 0, eIdx = 0;
    int sum = 0;

    while (true) {
        if (sum >= n)
            sum -= prime[sIdx++];
        else if (eIdx == prime.size())
            break;
        else
            sum += prime[eIdx++];

        if (sum == n)
            ans++;
    }

    cout << ans;

    return 0;
}