/*
    1789 - 수들의 합
*/

#include <iostream>

using namespace std;

long long n, sum;
int num = 1;
int ans;

int main() {

    cin >> n;

    while (true) {
        sum += num;
        ans++;

        if (sum > n) {
            ans--;
            break;
        }
        num++;
    }

    cout << ans << "\n";

    return 0;
}