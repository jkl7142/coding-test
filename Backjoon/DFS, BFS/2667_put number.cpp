/*
*   2667번 - 단지번호붙이기
*   coloring
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> map) {
    vector<int> answer;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    stack<pair<int, int>> stack;
    vector<vector<int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int acount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == '1' && visited[i][j] == 0) {
                int hcount = 0;
                acount++;
                stack.push(make_pair(i, j));
                visited[i][j] = acount;
                
                while (!stack.empty()) {
                    int currentRow = stack.top().first;
                    int currentCol = stack.top().second;
                    stack.pop();
                    hcount++;
                    
                    for (auto rc : moves) {
                        int nextRow = currentRow + rc[0];
                        int nextCol = currentCol + rc[1];

                        if (nextRow >= 0 && nextRow < n &&
                            nextCol >= 0 && nextCol < n &&
                            map[nextRow][nextCol] == '1') {
                            if (visited[nextRow][nextCol] == 0) {
                                stack.push(make_pair(nextRow, nextCol));
                                visited[nextRow][nextCol] = acount;
                            }
                        }
                    }
                }

                answer.push_back(hcount);
            }
        }
    }

    sort(answer.begin(), answer.end());
    
    answer.insert(answer.begin(), acount);

    return answer;
}

int main() {

    int n;
    cin >> n;
    vector<string> map;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        map.push_back(str);
    }

    for (auto r : solution(n, map)) {
        cout << r << "\n";
    }

    return 0;
}