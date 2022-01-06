/*
*   2261�� - ���� ����� �� ��
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<int, int>> location;

bool cmpX(pair<int, int>& p1, pair<int, int>& p2) {
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first < p2.first;
}

bool cmpY(pair<int, int>& p1, pair<int, int>& p2) {
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

// �� ���� �Ÿ��� ����
int distance(pair<int, int>& p1, pair<int, int>& p2) {
    int x = p1.first - p2.first;
    int y = p1.second - p2.second;
    return pow(x, 2) + pow(y, 2);
}

int solution(int left, int right) {
    int n = right - left + 1;
    if (n == 2)
        return distance(location[left], location[right]);
    if (n == 3)
        return min( min(distance(location[left], location[left + 1]),
                        distance(location[left + 1], location[left + 2])),
                    distance(location[left], location[right]) );

    int mid = (left + right) / 2;
    int answer = min(solution(left, mid), solution(mid + 1, right));

    // �߰��� �������� ����� ������ �迭�� ����
    vector<pair<int, int>> candi;
    // x��ǥ ���� �߰���
    int midLine = (location[mid].first + location[mid + 1].first) / 2;

    for (int i = left; i <= right; i++) {
        if (pow(midLine - location[i].first, 2) < answer)
            candi.push_back(location[i]);
    }

    // y��ǥ�� �������� Ž��
    sort(candi.begin(), candi.end(), cmpY);

    for (int i = 0; i < candi.size(); i++) {
        for (int j = i + 1; j < candi.size(); j++) {
            if (pow(candi[i].second - candi[j].second, 2) < answer)
                answer = min(answer, distance(candi[i], candi[j]));
            else
                break;
        }
    }

    return answer;
}

int main() {

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        location.push_back(make_pair(x, y));
    }

    // x��ǥ�� �������� ����
    sort(location.begin(), location.end(), cmpX);

    cout << solution(0, n - 1) << "\n";

    return 0;
}