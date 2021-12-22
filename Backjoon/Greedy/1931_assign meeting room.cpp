/*
*   1931번 - 회의실 배정
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int solution(vector<pair<int, int>>& meetings) {
    int answer = 0;

    sort(meetings.begin(), meetings.end(), cmp);

    int cur_end_time = 0;
    for (int i = 0; i < meetings.size(); i++) {
        if (cur_end_time <= meetings[i].first) {
            cur_end_time = meetings[i].second;
            answer++;
        }
    }

    return answer;
}

int main() {

    int n;
    cin >> n;
    vector<pair<int, int>> meetings;

    for (int i = 0; i < n; i++) {
        int start_time, end_time;
        cin >> start_time >> end_time;

        meetings.push_back(make_pair(start_time, end_time));
    }

    cout << solution(meetings) << "\n";

    return 0;
}