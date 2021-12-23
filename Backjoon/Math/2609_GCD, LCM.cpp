/*
*   2609�� - �ִ������� �ּҰ����
*   �ִ����� GCD Greatest Common Divisor
*   �ּҰ���� LCM Largest Common Multiple
*/

#include <iostream>
#include <numeric>

using namespace std;

// ��Ŭ���� ȣ����
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

    // <numeric> ���̺귯�� �Լ�
    // cout << gcd(a, b) << "\n";
    // cout << lcm(a, b) << "\n";

    return 0;
}