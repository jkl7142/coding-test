/*
*   10830번 - 행렬 제곱
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> operator*(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
            result[i][j] %= 1000;
        }
    }

    return result;
}

vector<vector<int>> solution(vector<vector<int>> matrix, long long b) {
    int n = matrix.size();
    vector<vector<int>> answer(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {   // 단위 행렬
        answer[i][i] = 1;
    }

    if (b == 1) {
        return matrix * answer;
    }
    else if (b % 2 == 0) {
        answer = solution(matrix, b / 2);
        return answer * answer;
    }
    else {
        answer = solution(matrix, b - 1);
        return matrix * answer;
    }

    //return answer;
}

int main() {

    int n;
    long long b;
    cin >> n >> b;
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            
            matrix[i][j] = num;
        }
    }

    for (auto row : solution(matrix, b)) {
        for (auto num : row) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}