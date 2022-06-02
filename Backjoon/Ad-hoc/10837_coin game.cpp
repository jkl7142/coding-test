/*
    10837 - 동전 게임
*/

#include <iostream>
#include <algorithm>

using namespace std;

int k, c;
int m, n;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> c;

    for (int i = 0; i < c; i++) {
        cin >> m >> n;

        if (m == n) {
            cout << 1 << "\n";
        }

        if (m < n) {
            if (n - m <= k - n + 1)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }

        if (m > n) {
            if (m - n <= k - m + 2)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
    }

    return 0;
}