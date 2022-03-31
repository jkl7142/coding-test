/*
    15686 - 치킨 배달
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define X first
#define Y second
#define MAX_N 51

int n, m, ans = 100'000'000;
int board[MAX_N][MAX_N];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) house.push_back({j, i});
            if (board[i][j] == 2) chicken.push_back({j, i});
        }
    }

    vector<int> selected(chicken.size() - m, 0);    // 폐업할 치킨집 : 0
    for (int i = 0; i < m; i++) selected.push_back(1);  // 선택할 치킨집 : 1
    // 선택한 치킨집의 순열
    do {
        int dist = 0;   // 도시의 치킨 거리
        for (pair<int, int> h : house) {
            int tmp = 100'000'000;  // 현재 집의 치킨 거리
            for (int i = 0; i < chicken.size(); i++) {
                if (selected[i] == 0)
                    continue;
                
                tmp = min(tmp, abs(chicken[i].X - h.X) + abs(chicken[i].Y - h.Y));
            }
            dist += tmp;
        }
        ans = min(dist, ans);

    } while (next_permutation(selected.begin(), selected.end()));

    cout << ans;

    return 0;
}