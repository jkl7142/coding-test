/*
*   2805번 - 나무 자르기
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long answer;

void solution(int m, long long left, long long right, vector<long long> trees) {
    if (left > right)
        return;

    int tSize = trees.size();
    long long mid = (left + right) / 2;
    long long length = 0;

    for (int i = 0; i < tSize; i++) {
        if (trees[i] - mid > 0) {
            length += trees[i] - mid;
        }
    }

    if (length >= m) {
        answer = max(answer, mid);
        solution(m, mid + 1, right, trees);
    }
    else {
        solution(m, left, mid - 1, trees);
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    long long maxVal = 0;
    vector<long long> trees;

    for (int i = 0; i < n; i++) {
        long long height;
        cin >> height;
        maxVal = max(maxVal, height);

        trees.push_back(height);
    }

    solution(m, 1, maxVal, trees);

    cout << answer << "\n";

    return 0;
}