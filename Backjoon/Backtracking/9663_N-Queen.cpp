/*
*   9663¹ø - N-Queen
*/

#include <iostream>
#include <vector>

using namespace std;

bool promising(int level, vector<int>& col) {
    for (int i = 0; i < level; i++) {
        if (col[i] == col[level] ||
            abs(col[level] - col[i]) == level - i)
            return false;
    }

    return true;
}

void nqueen(int level, int& n, vector<int>& col, int& answer) {
    if (level == n) {
        answer++;
    }
    else {
        for (int i = 0; i < n; i++) {
            col[level] = i;

            if (promising(level, col)) {
                nqueen(level + 1, n, col, answer);
            }
        }
    }
}

int solution(int n) {
    int answer = 0;
    vector<int> col(n);
    
    nqueen(0, n, col, answer);

    return answer;
}

int main() {

    int n;
    cin >> n;

    cout << solution(n) << "\n";

    return 0;
}