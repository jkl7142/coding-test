/*
*   2156번 - 포도주 시식
*   1. 포도주 잔을 선택하면 그 잔에 들어있는 포도주를 모두 마셔야 하고,
*   마신 후에는 원래 위치에 다시 놓아야 한다.
*   2. 연속으로 놓여 있는 3잔을 모두 마실 수는 없다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> wine) {
    int answer = 0;
    vector<int> DP(n + 1, 0);

    DP[1] = wine[0];
    DP[2] = wine[0] + wine[1];

    for (int i = 3; i <= n; i++) {
        DP[i] = max(DP[i - 1], max(DP[i - 2] + wine[i - 1],
                                    DP[i - 3] + wine[i - 2] + wine[i - 1]));
    }
    
    return answer = DP[n];
}

int main() {

    int n;
    cin >> n;
    vector<int> wine;
    
    for (int i = 0; i < n; i++) {
        int ml;
        cin >> ml;

        wine.push_back(ml);
    }

    cout << solution(n, wine) << "\n";

    return 0;
}