/*
*   1629¹ø - °ö¼À
*/

#include <iostream>

using namespace std;

long long solution(long long num, long long mNum, long long mod) {
    if (mNum == 0)
        return 1;
    else if (mNum == 1)
        return num % mod;

    long long temp;

    if (mNum % 2 == 0) {
        temp = solution(num, mNum / 2, mod) % mod;
        return temp * temp % mod;
    }
    else {
        temp = solution(num, mNum - 1, mod) % mod;
        return num * temp % mod;
    }   
}

int main() {

    long long num, mNum, mod;
    cin >> num >> mNum >> mod;

    cout << solution(num, mNum, mod) << "\n";

    return 0;
}