/*
*   1085 - 직사각형에서 탈출
*   직사각형의 경계선까지 가능 거리의 최솟값
*/

#include <iostream>
#include <vector>

using namespace std;

int solution(int x, int y, int w, int h) {
    int answer = 0;

    if (x > w / 2) x = w - x;
    if (y > h / 2) y = h - y;
    answer = (x < y) ? x : y; 

    return answer;
}

int main() {

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    cout << solution(x, y, w, h) << "\n";

    return 0;
}