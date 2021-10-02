/*
*   1002 - 터렛
*   (x1, y1), (x2, y2), r1, r2가 있을 때
*   (x3, y3)의 수
*/

#include <iostream>
#include <cmath>

using namespace std;

int solution(int x1, int y1, int r1, int x2, int y2, int r2) {
    int answer = -1;

    double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    
    if (dist == 0 && r1 == r2) return answer;
    else if (dist == r1 + r2 || dist == abs(r1 - r2)) answer = 1;
    else if (dist > abs(r1 - r2) && dist < r1 + r2) answer = 2;
    else answer = 0;

    return answer;
}

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        cout << solution(x1, y1, r1, x2, y2, r2) << "\n";
    }

    return 0;
}