/*
    11501 - 주식
*/

#include <iostream>

using namespace std;

#define MAX_N 1'000'001

int t, n;
int stockPrice[MAX_N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    for (int i = 0; i < t; i++) {
        long long ans = 0;
        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> stockPrice[j];
        }

        int maxPrice = stockPrice[n - 1];

        for (int j = n - 2; j >= 0; j--) {
            if (stockPrice[j] > maxPrice)
                maxPrice = stockPrice[j];

            ans += maxPrice - stockPrice[j];
        }

        cout << ans << "\n";
    }

    return 0;
}