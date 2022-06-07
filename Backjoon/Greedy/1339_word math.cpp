/*
    1339 - 단어 수학
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_N = 11;

int n, ans;
string words[MAX_N];
int alphaDigit[26]; // 알파벳 자릿수 체크, 예) ABC 이면, A : 100, B : 10, C : 1

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> words[i];

    for (int i = 0; i < n; i++) {
        int pow = 1;
        for (int j = words[i].size() - 1; j >= 0; j--) {
            alphaDigit[words[i][j] - 'A'] += pow;
            pow *= 10;
        }
    }

    sort(alphaDigit, alphaDigit + 26, greater<int>());

    int assignNum = 9;
    for (int i = 0; i < 26; i++) {
        if (alphaDigit[i] == 0)
            break;

        ans += alphaDigit[i] * assignNum;
        assignNum--;
    }

    cout << ans;

    return 0;
}