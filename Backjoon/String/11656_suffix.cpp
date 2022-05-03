/*
    11656 - 접미사 배열
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string str;
vector<string> suffix;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;

    int sSize = str.size();

    for (int i = 0; i < sSize; i++) {
        suffix.push_back(str.substr(i, sSize));
    }

    sort(suffix.begin(), suffix.end());

    for (string s : suffix) {
         cout << s << "\n";
    }

    return 0;
}