/*
*   2110번 - 공유기 설치
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int answer = 0;

void solution(int c, int left, int right, vector<int>& houses) {
    if (left > right)
        return;

    int hSize = houses.size();
    int mid = (left + right) / 2;
    int bi = 0;
    int insR = 1;
    
    for (int i = 1; i < hSize; i++) {
        if (houses[i] - houses[bi] >= mid) {
            bi = i;
            insR++;
        }
    }

    if (insR >= c) {
        answer = max(answer, mid);
        solution(c, mid + 1, right, houses);
    }
    else
        solution(c, left, mid - 1, houses);
}

int main() {

    int n, c;
    cin >> n >> c;

    vector<int> houses;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        houses.push_back(x);
    }
    
    sort(houses.begin(), houses.end());

    solution(c, 1, houses.back(), houses);

    cout << answer << "\n";

    return 0;
}