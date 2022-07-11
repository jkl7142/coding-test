/*
    2960 - 에라토스테네스의 체
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 10001;

int n, k, cnt;
int prime[MAX_N];

int main() {

    cin >> n >> k;

    for (int i = 2; i <= n; i++)
        prime[i] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; i * j <= n; j++) {
            if (prime[i * j] == 1) {
                prime[i * j] = 0;
                cnt++;

                if (cnt == k) {
                    cout << i * j << "\n";
                    return 0;
                }
            }
        }
    }

    return 0;
}