/*
*   2580? - ???
*/

#include <iostream>
#include <vector>

using namespace std;

bool promising(pair<int, int>& blank, vector<vector<int>>& sudoku) {
    int y = blank.first / 3;
    int x = blank.second / 3;

    int value = sudoku[blank.first][blank.second];

    for (int i = 0; i < 9; i++) {
        // ?? ?? ?? ?? ??? ??
        if (i != blank.second && value == sudoku[blank.first][i])
            return false;
        // ?? ?? ?? ?? ??? ??
        if (i != blank.first && value == sudoku[i][blank.second])
            return false;
    }

    // ??? ?? 3*3 ???? ?? ?? ??? ??
    for (int i = 3 * y; i < 3 * (y + 1); i++) {
        for (int j = 3 * x; j < 3 * (x + 1); j++) {
            if (i != blank.first && j != blank.second) {
                if (value == sudoku[i][j]) {
                    return false;
                }
            }
        }
    }

    return true;
}

void fillBlank(int idx, vector<pair<int, int>>& blank,
                vector<vector<int>>& sudoku, bool& finish) {

    if (idx == blank.size()) {
        finish = true;
        return;
    }
    else {
        for (int i = 1; i <= 9; i++) {
            sudoku[blank[idx].first][blank[idx].second] = i;
            
            if (promising(blank[idx], sudoku)) {
                fillBlank(idx + 1, blank, sudoku, finish);
            }

            if (finish)
                return;
        }
    }

    sudoku[blank[idx].first][blank[idx].second] = 0;
}

void solution(vector<vector<int>>& sudoku) {
    vector<pair<int, int>> blank;
    bool finish = false;

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (sudoku[row][col] == 0) {
                blank.push_back(make_pair(row, col));
            }
        }
    }

    fillBlank(0, blank, sudoku, finish);
}

int main() {

    vector<vector<int>> sudoku(9, vector<int>(9, 0));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
        }
    }

    solution(sudoku);

    for (auto line : sudoku) {
        for (auto num : line) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}