/*
*   7562번 - 나이트의 이동
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int solution(int length, int row, int col, int endRow, int endCol) {
    int answer = 0;
    vector<vector<int>> visited(length, vector<int>(length, 0));
    queue<pair<int, int>> queue;

    vector<vector<int>> moves = {{1, 2}, {2, 1}, {2, -1}, {1, -2},
                                {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};

    queue.push(make_pair(row, col));
    visited[row][col] = 1;

    while (!queue.empty()) {
        int currentRow = queue.front().first;
        int currentCol = queue.front().second;
        queue.pop();

        if (currentRow == endRow && currentCol == endCol) {
            answer = visited[currentRow][currentCol] - 1;
            return answer;
        }

        for (auto rc : moves) {
            int nextRow = currentRow + rc[0];
            int nextCol = currentCol + rc[1];

            if (nextRow >= 0 && nextRow < length && nextCol >= 0 && nextCol < length) {
                if (visited[nextRow][nextCol] == 0 ||
                    visited[nextRow][nextCol] > visited[currentRow][currentCol] + 1) {
                    queue.push(make_pair(nextRow, nextCol));
                    visited[nextRow][nextCol] = visited[currentRow][currentCol] + 1;
                }
            }
        }
    }
}

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int l, r, c, er, ec;
        cin >> l >> r >> c >> er >> ec;

        cout << solution(l, r, c, er, ec) << "\n";
    }

    return 0;
}