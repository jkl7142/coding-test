/*
    2581�� - �Ҽ�
    �ڿ��� M�� N�� �־��� ��
    M�̻� N������ �ڿ��� �� �Ҽ��� ���� ��� ���
    �̵� �Ҽ��� �հ� �ּڰ��� ã�� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n == 1)
        return false;
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

vector<int> solution(int m, int n) {
    vector<int> answer;
    int sum = 0, min = 0;

    for (int i = m; i <= n; i++) {
        if (isPrime(i)) {
            if (min == 0) min = i;
            sum += i;
        }
    }

    if (sum) {
        answer.push_back(sum);
        answer.push_back(min);
    }
    else {
        answer.push_back(-1);
    }

    return answer;
}

int main() {

    int M, N;
    cin >> M >> N;

    for (auto n : solution(M, N)) {
        cout << n << endl;
    }

    return 0;
}