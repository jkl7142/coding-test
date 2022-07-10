/*
    1057 - 토너먼트
*/

#include <iostream>

using namespace std;

int n;
int round = 1, par1, par2;

int main() {

    cin >> n;
    cin >> par1 >> par2;

    while (n) {
        if ((par1 + 1) / 2 == (par2 + 1) / 2)
            break;

        par1 = (par1 + 1) / 2;
        par2 = (par2 + 1) / 2;
        round ++;
        n /= 2;
    }

    if (n == 0)
        cout << -1 << "\n";
    else
        cout << round << "\n";

    return 0;
}