/*
    1213 - 팰린드롬 만들기
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string name;
int alpha[26];
string oddA, evenA;

int main() {

    cin >> name;
    for (auto c : name)
        alpha[c]++;

    for (char i = 'A'; i <= 'Z'; i++) {
        if (alpha[i] % 2 == 1)
            oddA += i;

        for (int j = 0; j < alpha[i] / 2; j++)
            evenA += i;
    }

    if (oddA.size() > 1)
        cout << "I'm Sorry Hansoo";
    else {
        cout << evenA << oddA;
        reverse(evenA.begin(), evenA.end());
        cout << evenA;
    }

    return 0;
}