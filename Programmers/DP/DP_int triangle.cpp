#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int depth = triangle.size();
    vector<vector<int>> DP(depth, vector<int>(depth, 0));
    DP[0][0] = triangle[0][0];

    for (int i = 1; i < depth; i++) {
        int breadth = triangle[i].size();
        for (int j = 0; j < breadth; j++) {
            if (j == 0) {
                DP[i][j] = triangle[i][j] + DP[i - 1][j];
            }
            else if (j == breadth - 1) {
                DP[i][j] = triangle[i][j] + DP[i - 1][j - 1];
            }
            else {
                DP[i][j] = triangle[i][j] + max(DP[i - 1][j], DP[i - 1][j - 1]);
            }
        }
    }

    for (int i = 0; i < depth; i++) {
        if (answer < DP[depth - 1][i])
            answer = DP[depth - 1][i];
    }

    return answer;
}

int main() {

    vector<vector<int>> tri = {{7}, {3, 8}, {8, 1, 0},
                               {2, 7, 4, 4}, {4, 5, 2, 6, 5}};

    cout << solution(tri) << endl;

    return 0;
}