/*
    2448¹ø - º° Âï±â - 11
*/

#include <iostream>

using namespace std;

const int MAX = 1024 * 3 + 2;

int n;
char board[MAX][MAX * 2 - 1];

void fillStar(const int& x, const int& y) {
    board[x][y] = '*';
    board[x + 1][y - 1] = '*', board[x + 1][y + 1] = '*';

    for (int i = y - 2; i <= y + 2; ++i) {
        board[x + 2][i] = '*';
    }
}

void recur(const int& s, const int& x, const int& y) {
    if (s == 3) {
        fillStar(x, y);
        return;
    }

    int ns = s / 2;
    recur(ns, x, y);
    recur(ns, x + ns, y - ns);
    recur(ns, x + ns, y + ns);
}

int main() {
    int n;
    cin >> n;   // n = 3 * 2^k (0 <= k <= 10)

    recur(n, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < n * 2 - 1; ++ii) {
            if (board[i][ii] == '*')
                cout << '*';
        else
            cout << ' ';
        }
        cout << "\n";
    }

    return 0;
}