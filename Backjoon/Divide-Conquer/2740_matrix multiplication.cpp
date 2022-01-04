/*
*   2740¹ø - Çà·Ä °ö¼À
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> A, vector<vector<int>> B) {
    vector<vector<int>> answer(A.size(), vector<int>(B[0].size(), 0));

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B[0].size(); j++) {
            for (int k = 0; k < A[0].size(); k++) {
                answer[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return answer;
}

int main() {

    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> matrixA(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;

            matrixA[i][j] = num;
        }
    }

    cin >> m >> k;
    vector<vector<int>> matrixB(m, vector<int>(k, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            int num;
            cin >> num;

            matrixB[i][j] = num;
        }
    }

    for (auto row : solution(matrixA, matrixB)) {
        for (auto num : row) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}