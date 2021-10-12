/*
*   11726번 - 2*n 타일링
*   2*n 크기의 직사각형을 1*2, 2*1 타일로 채우는 방법의 수
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> DP(n + 1, 1);    

    DP[2] = 2;
    for (int i = 3; i <= n; i++) {
        DP[i] = (DP[i - 2] + DP[i - 1]) % 10007;
    }

    return answer = DP[n];
}

int main() {

    int n;
    cin >> n;

    cout << solution(n) << "\n";


    return 0;
}