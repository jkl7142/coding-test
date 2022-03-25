/*
*   2447�� - �� ��� - 10
*
*       ***
*       * *
*       ***     // N = 3, 9, 27, ...
*
*   ���� ����
*   ��� �Լ�
*/

// Ǯ�� 1
#include <iostream>

using namespace std;

void printStar(int x, int y, int n) {
    if ((x / n) % 3 == 1 && (y / n) % 3 == 1)
        cout << " ";
    else if (n / 3 == 0)
        cout << "*";
    else
        printStar(x, y, n / 3);
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printStar(j, i, n / 3);
        }
        cout << "\n";
    }

    return 0;
}


// Ǯ�� 2
/* 
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
*/