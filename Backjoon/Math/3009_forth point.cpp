/*
*   3009번 - 네 번째 점
*   세 점이 주어졌을 때,
*   직사각형을 만들기 위한 네 번째 점을 찾으시오.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> solution(vector<pair<int, int>> points) {
    vector<pair<int, int>> answer;
    int x, y;
    int mid = 1;
    
    if (points[mid].first == points[mid - 1].first) {
        x = points[mid + 1].first;
    }
    else if (points[mid].first == points[mid + 1].first) {
        x = points[mid - 1].first;
    }
    else {
        x = points[mid].first;
    }

    if (points[mid].second == points[mid - 1].second) {
        y = points[mid + 1].second;
    }
    else if (points[mid].second == points[mid + 1].second) {
        y = points[mid - 1].second;
    }
    else {
        y = points[mid].second;
    }

    answer.push_back(make_pair(x, y));

    return answer;
}

int main() {

    int x, y;
    vector<pair<int, int>> points;

    for (int i = 0; i < 3; i++) {
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    for (auto n : solution(points)) {
        cout << n.first << " " << n.second << "\n";
    }

    return 0;
}