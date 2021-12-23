/*
*   2609번 - 최대공약수와 최소공배수
*   최대공약수 GCD Greatest Common Divisor
*   최소공배수 LCM Largest Common Multiple
*/

#include <iostream>
#include <numeric>

using namespace std;

// 유클리드 호제법
int GCD(int a, int b) {
    int answer = 0;

    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }

    return answer = a;
}

int LCM(int a, int b) {
    int answer = 0;

    answer = a * (b / GCD(a, b));

    return answer;
}

int main() {

    int a, b;
    cin >> a >> b;

    cout << GCD(a, b) << "\n";
    cout << LCM(a, b) << "\n";

    // <numeric> 라이브러리 함수
    // cout << gcd(a, b) << "\n";
    // cout << lcm(a, b) << "\n";

    return 0;
}