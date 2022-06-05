/*
    15927 - 회문은 회문아니야!!
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str, preStr, postStr;
bool allSame = true;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    preStr = str.substr(0, str.size() / 2);
    if (str.size() % 2 == 0)
        postStr = str.substr(str.size() / 2);
    else
        postStr = str.substr(str.size() / 2 + 1);

    reverse(postStr.begin(), postStr.end());

    if (preStr == postStr) {
        for (int i = 0; i < str.size() - 1; i++) {
            // 문자가 같지 않은 팰린드롬이면
            if (str[i] != str[i + 1]) {
                cout << str.size() - 1;
                allSame = false;
                break;
            }
        }
        // 문자가 모두 같은 팰린드롬
        if (allSame)
            cout << -1;
    }
    // 팰린드롬이 아니면
    else
        cout << str.size();

    return 0;
}