/*
*   14889번 - 스타트와 링크
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> abilities(20, vector<int>(20));
vector<bool> visited(20, false);
int n, answer = 400;

void solution(int idx, int count) {
    if (count == n / 2) {
        int start = 0;
        int link = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (visited[i] && visited[j] && i != j) {
                    start += abilities[i][j];
                    start += abilities[j][i];
                }
                if (!visited[i] && !visited[j] && i != j) {
                    link += abilities[i][j];
                    link += abilities[j][i];
                }
            }
        }

        answer = min(answer, abs(start - link));
    }

    for (int i = idx; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            solution(i, count + 1);
            visited[i] = false;
        }
    }
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int ability;
            cin >> ability;
            abilities[i][j] = ability;
        }
    }

    solution(0, 0);

    cout << answer << "\n";

    return 0;
}