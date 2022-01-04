/*
*   2630번 - 색종이 만들기
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> paper;
int whitePaper = 0;
int bluePaper = 0;

void solution(int y, int x, int size) {
    bool divide = false;
    int basedColor = paper[y][x];

    for (int row = y; row < y + size; row++) {
        for (int col = x; col < x + size; col++) {
            if (basedColor != paper[row][col]) {
                divide = true;
                break;
            }
        }
        if (divide)
            break;
    }

    if (divide) {
        solution(y, x, size / 2);
        solution(y, x + size / 2, size / 2);
        solution(y + size / 2, x, size / 2);
        solution(y + size / 2, x + size / 2, size / 2);
    }
    else {
        if (basedColor) {
            bluePaper++;
        }
        else {
            whitePaper++;
        }
    }
}

int main() {
    int n;
    cin >> n;

    paper = vector<vector<int>>(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int color;
            cin >> color;
            if (color == 1)
                paper[i][j] = color;
        }
    }

    solution(0, 0, n);

    cout << whitePaper << "\n";
    cout << bluePaper << "\n";

    return 0;
}