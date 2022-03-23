/*
    1074�� - Z
*/

#include <iostream>

using namespace std;

int recur(int n, int r, int c) {
    if (n == 0)
        return 0;

    int half = 1 << (n - 1);

    if (r < half && c < half)   // ���� �� ��и�
        return recur(n - 1, r, c);
    if (r < half && c >= half)  // ������ �� ��и�
        return half * half + recur(n - 1, r, c - half);
    if (r >= half && c < half)  // ���� �Ʒ� ��и�
        return 2 * half * half + recur(n - 1, r - half, c);
    else                        // ������ �Ʒ� ��и�
        return 3 * half * half + recur(n - 1, r - half, c - half);
}

int main() {

    int n, r, c;
    cin >> n >> r >> c;

    cout << recur(n, r, c) << "\n";

    return 0;
}