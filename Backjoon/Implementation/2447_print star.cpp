/*
*   2447번 - 별 찍기 - 10
*
*       ***
*       * *
*       ***     // N = 3, 9, 27, ...
*
*   분할 정복
*   재귀 함수
*/

#include <iostream>

using namespace std;

void printStar(int i, int j, int n) {
    if ((i / n) % 3 == 1 && (j / n) % 3 == 1) {
        cout << " ";
    }
    else if (n / 3 == 0) {
        cout << "*";
    }
    else {
        printStar(i, j, n / 3);
    }
}

void recurStar(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printStar(i, j, n);
        }
        cout << "\n";
    }
}

int main() {

    int n;
    cin >> n;

    recurStar(n);

    return 0;
}