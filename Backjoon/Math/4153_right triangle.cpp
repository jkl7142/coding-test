/*
*   4153번 - 직각삼각형
*   피타고라스의 정리
*/

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

string solution(int a, int b, int c) {
    string answer = "";
    
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);

    if (pow(c, 2) == pow(a, 2) + pow(b, 2)) answer = "right";
    else answer = "wrong";

    return answer;
}

int main() {

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a + b + c == 0) break;

        cout << solution(a, b, c) << "\n";
    }

    return 0;
}