/*
*   1992번 - 쿼드트리
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> quadtree;
string compression = "";

void solution(int y, int x, int size) {
    char basedPixel = quadtree[y][x];

    for (int row = y; row < y + size; row++) {
        for (int col = x; col < x + size; col++) {
            if (basedPixel != quadtree[row][col]) {
                compression += "(";
                solution(y, x, size / 2);
                solution(y, x + size /2, size / 2);
                solution(y + size / 2, x, size / 2);
                solution(y + size / 2, x + size / 2, size / 2);
                compression += ")";
                return;
            }
        }
    }

    compression += basedPixel;
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        quadtree.push_back(str);
    }

    solution(0, 0, n);

    cout << compression << "\n";

    return 0;
}