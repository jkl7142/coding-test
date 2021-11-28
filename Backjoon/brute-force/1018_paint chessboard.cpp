/*
*   1018번 - 체스판 다시 칠하기
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> chessB = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

vector<string> chessW = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

int solution(vector<string> chessboard) {
    int answer = 32;
    int startRow = 0, startCol = 0, endRow = 8, endCol = 8;
    
    while (endRow <= chessboard.size() && endCol <= chessboard[0].size()) {
        char first = chessboard[startRow][startCol];
        int refillB = 0;
        int refillW = 0;

        for (int row = startRow; row < endRow; row++) {
            for (int col = startCol; col < endCol; col++) {
                if (chessboard[row][col] != chessB[row - startRow][col - startCol])
                    refillB++;

                if (chessboard[row][col] != chessW[row - startRow][col - startCol])
                    refillW++;
            }
        }

        if (endCol == chessboard[0].size()) {
            startRow++, endRow++;
            startCol = 0; endCol = 8;
        }
        else {
            startCol++, endCol++;
        }

        if (refillB < refillW && answer > refillB) answer = refillB;
        else if (answer > refillW) answer = refillW;
    }

    return answer;
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<string> chessboard;

    for (int i = 0; i < n; i++) {
        string colors = "";
        for (int j = 0; j < m; j++) {
            char color;
            cin >> color;
            colors += color;
        }
        chessboard.push_back(colors);
    }

    cout << solution(chessboard) << "\n";

    return 0;
}