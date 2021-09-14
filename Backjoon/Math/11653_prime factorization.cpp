/*
*   11653�� - ���μ�����
*   ���� N�� �־����� ��,
*   ���μ����� ����� �� �ٿ� �ϳ��� ����Ͻÿ�.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;

    for (int i = 2; i <= sqrt(n); i++) {
        while (n % i == 0) {
            answer.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        answer.push_back(n);
    }

    return answer;
}

int main() {

    int N;
    cin >> N;

    for (auto n : solution(N)) {
        cout << n << endl;
    }

    return 0;
}