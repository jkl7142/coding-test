#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;

    int hCount = money.size();
    int fMax = 0, sMax = 0;
    vector<int> fDP(hCount + 1, 0);
    vector<int> sDP(hCount + 1, 0);

    // 1. 첫 번째 집부터 시작
    fDP[1] = money[0];
    for (int i = 2; i < hCount; i++) {
        fDP[i] = max(fDP[i - 1], fDP[i - 2] + money[i - 1]);
    }

    fMax = fDP[hCount - 1];

    // 2. 두 번째 집부터 시작
    for (int i = 2; i <= hCount; i++) {
        sDP[i] = max(sDP[i - 1], sDP[i - 2] + money[i - 1]);
    }

    sMax = sDP[hCount];

    return answer = max(fMax, sMax);
}

int main() {

    vector<int> money = {10, 2, 2, 100, 2};

    cout << solution(money) << "\n";

    return 0;
}