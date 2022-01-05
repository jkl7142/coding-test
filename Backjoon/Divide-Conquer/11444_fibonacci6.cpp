/*
*   11444번 - 피보나치 수 6
*   (Fn+2)      (1 1) (Fn+1)
*   (Fn+1)  =   (1 0) ( Fn )
*
*   (Fn+1  Fn )     (1  1) ^ n
*   ( Fn  Fn-1)  =  (1  0)
*
*/

#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;

vector<vector<long long>> operator*(vector<vector<long long>> A, vector<vector<long long>> B) {
    int n = A.size();
    vector<vector<long long>> result(n, vector<long long>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
            result[i][j] %= MOD;
        }
    }

    return result;
}

long long solution(long long n) {
    vector<vector<long long>> fibMatrix = {{1, 1},
                                           {1, 0}};

    vector<vector<long long>> temp = {{1, 0},
                                      {0, 1}};

    while (n > 0) {
        if (n % 2 == 1) {
            temp = temp * fibMatrix;
        }
        fibMatrix = fibMatrix * fibMatrix;
        n /= 2;
    }

    return temp[0][1];
}

int main() {

    long long n;
    cin >> n;
    
    cout << solution(n) << "\n";

    return 0;
}