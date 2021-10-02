/*
*   9020 - �������� ����
*   2���� ū ��� ¦���� �� �Ҽ��� ������ ��Ÿ�� �� �ִٴ� ���̴�.
*   ¦���� �� �Ҽ��� ������ ��Ÿ���� ǥ���� �� ���� ������ ��Ƽ���̶�� �Ѵ�.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> prime(10001 * 2, 1);  // 0 : non-prime, 1 : prime

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

priority_queue<int, vector<int>, greater<int>> solution(int n) {
    priority_queue<int, vector<int>, greater<int>> answer;

    isPrime(n);

    for (int i = n / 2; i <= n; i++) {
        for (int j = n / 2; j >= 0; j--) {
            if (prime[i] && prime[j] && n == i + j) {
                answer.push(i);
                answer.push(j);

                return answer;
            }
        }
    }

    return answer;
}

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        priority_queue<int, vector<int>, greater<int>> result(solution(n));
        while (!result.empty()) {
            cout << result.top() << " ";
            result.pop();
        }
        cout << endl;
    }

    return 0;
}