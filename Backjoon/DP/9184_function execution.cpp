/*
*   9184번 - 신나는 함수 실행
*   재귀 함수 DP로 작성
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<vector<int>>> DP(21, vector<vector<int>>(21, vector<int>(21, 1)));

int solution(int a, int b, int c) {

    // base case
    if (a <= 0 || b <= 0 || c <= 0)
        return DP[0][0][0];

    if (a > 20 || b > 20 || c > 20)
        return solution(20, 20, 20);

    // DP return
    if (DP[a][b][c] != 1)
        return DP[a][b][c];

    // induction step
    if (a < b && b < c)
        return DP[a][b][c] = solution(a, b, c - 1) + solution(a, b - 1, c - 1)
                            - solution(a, b - 1, c);

    return DP[a][b][c] = solution(a - 1, b, c) + solution(a - 1, b - 1, c)
                        + solution(a - 1, b, c - 1) - solution(a - 1, b - 1, c - 1);

}

int main() {

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
            break;

        cout << "w(" << a << ", " << b << ", " << c << ") = "
            << solution(a, b, c) << "\n";
    }

    return 0;
}