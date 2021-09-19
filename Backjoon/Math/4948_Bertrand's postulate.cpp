/*
*   4948 - ����Ʈ�� ����
*   n���� ũ�� 2n���� �۰ų� ���� �Ҽ��� ��� �ϳ� �����Ѵ�.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> prime(123457 * 2, 1);  // 0 : non-prime, 1 : prime

void isPrime(int n) {
    prime[1] = 0;
    
    for (int i = 2; i <= sqrt(2 * n); i++) {
        if (prime[i]) {
            for (int j = i * 2; j <= 2 * n; j += i) {
                prime[j] = 0;
            }
        }
        
    }
}

int solution(int n) {
    int primeCount = 0;

    isPrime(n);

    for (int i = n + 1; i <= 2 * n; i++) {
        if (prime[i]) {
            primeCount++;
        }
    }

    return primeCount;
}

int main() {

    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }
        else {
            cout << solution(n) << "\n";
        }
    }

    return 0;
}