/*
    2457 - 공주님의 정원
*/

#include <iostream>
#include <vector>

using namespace std;

int n, ans;
int sm, sd, em, ed;
vector<pair<int, int>> flowers;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> sm >> sd >> em >> ed;
        flowers.push_back({ sm * 100 + sd, em * 100 + ed }); // 100의 자리 이상은 month, 미만은 day
    }

    int curTime = 301;
    while (curTime < 1201) {
        int nextTime = curTime;
        for (int i = 0; i < n; i++) {
            if (flowers[i].first <= curTime && flowers[i].second > nextTime)
                nextTime = flowers[i].second;
        }

        if (nextTime == curTime) {
            cout << "0";
            return 0;
        }

        ans++;
        curTime = nextTime;
    }

    cout << ans;

    return 0;
}