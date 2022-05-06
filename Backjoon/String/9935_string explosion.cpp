/*
    9935 - 문자열 폭발
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str, exp;
string eStack;

int main() {

    cin >> str >> exp;

    for (int i = 0; i < str.size(); i++) {
        eStack.push_back(str[i]);
        
        if (exp.back() == eStack.back()) {
            bool explosion = true;
            for (int j = 1; j <= exp.size(); j++) {
                if (eStack[eStack.size() - j] != exp[exp.size() - j]) {
                    explosion = false;
                    break;
                }
            }
            
            if (explosion) {
                for (int j = 0; j < exp.size(); j++)
                    eStack.pop_back();
            }
        }
    }

    if (eStack.empty())
        cout << "FRULA";
    else
        cout << eStack;

    return 0;
}