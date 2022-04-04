/*
    11652 - Ä«µå
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100'001

using namespace std;

int n, cnt, maxCnt;
long long maxVal = -(1ll << 62) - 1;
vector<long long> cards;

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        long long card;
        cin >> card;
        cards.push_back(card);
    }

    sort(cards.begin(), cards.end());
    
    for (int i = 0; i < n; i++) {
        if (i == 0 || cards[i - 1] == cards[i])
            cnt++;
        else {
            if (cnt > maxCnt) {
                maxCnt = cnt;
                maxVal = cards[i - 1];
            }
            cnt = 1;
        }
    }

    if (cnt > maxCnt)
        maxVal = cards[n - 1];
    
    cout << maxVal;

    return 0;
}