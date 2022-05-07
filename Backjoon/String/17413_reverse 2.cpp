/*
    17413 - 단어 뒤집기 2
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
bool tag;
stack<char> s;

void stackPop() {
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
}

int main() {
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, str);

    for (int i = 0; i < str.size(); i++) {
        char c = str[i];

        if (c == '<') {
            stackPop();
            tag = true;
            cout << c;
        }
        else if (c == '>') {
            tag = false;
            cout << c;
        }
        else if (c == ' ') {
            stackPop();
            cout << c;
        }
        else if (tag) {
            cout << c;
        }
        else {  // !tag
            s.push(c);
        }
    }

    stackPop();

    return 0;
}