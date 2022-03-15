/*
*   9663번 - N-Queen
*/

#include <iostream>
#include <vector>

using namespace std;

bool promising(int level, vector<int>& board) {
    for (int i = 0; i < level; i++) {
        if (board[i] == board[level] ||
            abs(board[level] - board[i]) == level - i)
            return false;
    }

    return true;
}

void nqueen(int level, int& n, vector<int>& board, int& answer) {
    if (level == n) {
        answer++;
    }
    else {
        for (int i = 0; i < n; i++) {
            board[level] = i;

            if (promising(level, board)) {
                nqueen(level + 1, n, board, answer);
            }
        }
    }
}

int solution(int n) {
    int answer = 0;
    vector<int> board(n);
    
    nqueen(0, n, board, answer);

    return answer;
}

int main() {

    int n;
    cin >> n;
    cout << solution(n) << "\n";

    return 0;
}   