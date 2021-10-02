/*
*   1085 - ���簢������ Ż��
*   ���簢���� ��輱���� ���� �Ÿ��� �ּڰ�
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