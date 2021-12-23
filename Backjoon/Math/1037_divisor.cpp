/*
*   1037¹ø - ¾à¼ö
*/

#include <iostream>

using namespace std;

int main() {

    int n, max = 2, min = 1000000;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int divisor;
        cin >> divisor;

        if (divisor > max)
            max = divisor;
        if (divisor < min)
            min = divisor;
    }

    cout << max * min << "\n";

    return 0;
}