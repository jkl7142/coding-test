/*
*   2178? - ?? ??
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int solution(int n, int m, vector<string> map) {
    int answer = 0;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> queue;
    vector<vector<int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    queue.push(make_pair(0, 0));
    visited[0][0] = 1;

    while (!queue.empty()) {
        int x = queue.front().first;
        int y = queue.front().second;
        queue.pop();

        if (x == n - 1 && y == m - 1) {
            answer = visited[x][y];
            break;
        }
        
        for (auto xy : moves) {
            int nx = x + xy[0];
            int ny = y + xy[1];

            if (nx >= 0 & nx < n && ny >= 0 && ny < m && map[nx][ny] == '1') {
                if (visited[nx][ny] == 0 || visited[nx][ny] > visited[x][y] + 1) {
                    queue.push(make_pair(nx, ny));
                    visited[nx][ny] = visited[x][y] + 1;
                }
            }
        }
    }

    return answer;
}

int main() {

    int N, M;
    cin >> N >> M;

    vector<string> map;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        map.push_back(str);
    }

    cout << solution(N, M, map) << "\n";

    return 0;
}