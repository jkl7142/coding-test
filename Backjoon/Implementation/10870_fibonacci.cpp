/*
*   10870�� - �Ǻ���ġ ���� 0 1 1 2 3 5 8 13
*   Fn = fn-1 + Fn-2 (n >= 2)
*   ��� �Լ�
*/

#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n) {
    if (n < 2) return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {

    int n;
    cin >> n;

    cout << fibonacci(n) << "\n";

    return 0;
}