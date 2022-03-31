/*
    15686 - ġŲ ���
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

    vector<int> selected(chicken.size() - m, 0);    // ����� ġŲ�� : 0
    for (int i = 0; i < m; i++) selected.push_back(1);  // ������ ġŲ�� : 1
    // ������ ġŲ���� ����
    do {
        int dist = 0;   // ������ ġŲ �Ÿ�
        for (pair<int, int> h : house) {
            int tmp = 100'000'000;  // ���� ���� ġŲ �Ÿ�
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