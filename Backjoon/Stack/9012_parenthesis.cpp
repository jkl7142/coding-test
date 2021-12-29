/*
*   9012¹ø - °ýÈ£
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

void solution(vector<string> pString) {

    for (int i = 0; i < pString.size(); i++) {
        stack<char> stack;
        bool vps = true;

        for (int j = 0; j < pString[i].length(); j++) {
            char pChar = pString[i][j];

            if (pChar == '(') {
                stack.push(pChar);
            }
            else {  // ')'
                if (stack.empty()) {
                    vps = false;
                    break;
                }
                else {
                    stack.pop();
                }
            }
        }

        if (!stack.empty()) {
            vps = false;
        }

        if (vps) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
}

int main() {

    int t;
    cin >> t;
    vector<string> pString;

    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;

        pString.push_back(str);
    }

    solution(pString);

    return 0;
}