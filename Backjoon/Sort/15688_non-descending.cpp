/*
    15688 - 수 정렬하기 5
*/

#include <iostream>
#include <vector>

#define MAX_N 2'000'000
#define HALF MAX_N / 2

using namespace std;

int n, num;
int numCnt[MAX_N + 2];

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        numCnt[num + HALF]++;
    }

    for (int i = 0; i <= MAX_N; i++)
        while (numCnt[i]--)
            cout << i - HALF << "\n";

    return 0;
}