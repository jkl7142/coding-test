/*
    9625 - BABBA
*/

#include <iostream>

using namespace std;

const int MAX_N = 46;

int n;
int cntA[MAX_N], cntB[MAX_N];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cntA[0] = 1;
    cntA[1] = 0;
    cntB[0] = 0;
    cntB[1] = 1;

    for (int i = 2; i <= n; i++) {
        cntA[i] = cntB[i - 1];
        cntB[i] = cntB[i - 1] + cntA[i - 1];
    }

    cout << cntA[n] << " " << cntB[n] << "\n";

    return 0;
}