/*
*   1929번 - 소수 구하기
*   M이상 N이하의 소수를 모두 출력하시오.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> prime(1000001, 1); // 0 : non-prime, 1 : prime

void isPrime(int n) {
    prime[1] = 0;
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (prime[i]) {
            for (int j = i * 2; j <= n; j += i) {
                prime[j] = 0;
            }
        }
        
    }
}

vector<int> solution(int m, int n) {
    vector<int> answer;

    isPrime(n);

    for (int i = m; i <= n; i++) {
        if (prime[i]) {
            answer.push_back(i);
        }
    }

    return answer;
}

int main() {

    int M, N;
    cin >> M >> N;

    for (auto n : solution(M, N)) {
        cout << n << "\n";
    }

    return 0;
}