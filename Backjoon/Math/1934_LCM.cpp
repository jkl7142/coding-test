/*
*   1934번 - 최소공배수
*/

#include <iostream>

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

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        cout << LCM(a, b) << "\n";
    }

    return 0;
}