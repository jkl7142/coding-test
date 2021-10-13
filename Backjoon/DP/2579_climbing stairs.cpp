/*
*   2579번 - 계단 오르기
*   계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
*   연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
*   마지막 도착 계단은 반드시 밟아야 한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> stairs) {
    int answer = 0;
    vector<int> DP(n + 1, 0);

    DP[1] = stairs[1];
    DP[2] = stairs[1] + stairs[2];
    
    for (int i = 3; i <= n; i++) {
        DP[i] = max(DP[i - 2] + stairs[i],
                    DP[i - 3] + stairs[i - 1] + stairs[i]);
    }

    return answer = DP[n];
}

int main() {

    int n;
    cin >> n;
    vector<int> stairs(n + 1, 0);

    for (int i = 0; i < n; i++) {
        int stair;
        cin >> stair;

        stairs[i + 1] = stair;
    }

    cout << solution(n, stairs) << "\n";

    return 0;
}