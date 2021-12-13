/*
*   11651번 - 좌표 정렬하기 2
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

void solution(vector<pair<int, int>>& coordinate) {
    sort(coordinate.begin(), coordinate.end(), cmp);
}

int main() {

    int n;
    cin >> n;

    vector<pair<int, int>> coordinate;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        coordinate.push_back(make_pair(x, y));
    }
    
    solution(coordinate);

    for (auto p : coordinate) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}