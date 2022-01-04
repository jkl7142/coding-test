/*
*   11401번 - 이항 계수 3
*   nCk = n! / k!(n - k)!
*   페르마의 소정리
*   : p가 소수이고 a가 p의 배수가 아니면 a^p-1 == 1 (mod p) 이다.
*   : 즉, a^p-1을 p로 나눈 나머지는 1이다.
*   -> a*a^p-2 == 1 (mod p) => a^p-2 == a^-1 (mod p)
*   => (n! / k!(n - k)!) % p == n!%p * (k!(n - k)!)^p-2 % p
*   (분모 부분을 분자의 mod p 형태로 바꿀 수 있다.)
*/

#include <iostream>

using namespace std;

const long long MOD = 1000000007;

long long fact(int n) {
    if (n == 0 || n == 1)
        return 1;

    return n * fact(n - 1) % MOD;
}

long long pow(int num, int mNum) {
    if (mNum == 0)
        return 1;
    if (mNum == 1)
        return num % MOD;
    
    long long temp;

    if (mNum % 2 == 0) {
        temp = pow(num, mNum / 2);
        return temp * temp % MOD;
    }
    else {
        temp = pow(num, mNum - 1);
        return num * temp % MOD;
    }
}

long long solution(int n, int k) {
    if (n == 0 || k == 0 || k == n)
        return 1;

    return fact(n) * pow(fact(k) * fact(n - k) % MOD, MOD - 2) % MOD;
}

int main() {

    int n, k;
    cin >> n >> k;

    cout << solution(n, k) << "\n";

    return 0;
}