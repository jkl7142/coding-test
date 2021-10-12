/*
*   1932번 - 정수 삼각형
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> triangle) {
    int answer = triangle[0][0];
    vector<vector<int>> DP(n, vector<int>(n, 0));

    DP[0][0] = triangle[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                DP[i][j] = DP[i - 1][j] + triangle[i][j];
            }
            else if (j == i) {
                DP[i][j] = DP[i - 1][j - 1] + triangle[i][j];
            }
            else {
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - 1]) + triangle[i][j];
            }

            answer = max(answer, DP[i][j]);
        }
    }

    return answer;
}

int main() {

    int n;
    cin >> n;
    vector<vector<int>> triangle;

    for (int i = 0; i < n; i++) {
        vector<int> line;
        
        for (int j = 0; j <= i; j++) {
            int num;
            cin >> num;

            line.push_back(num);
        }

        triangle.push_back(line);
    }

    cout << solution(n, triangle) << "\n";

    return 0;
}