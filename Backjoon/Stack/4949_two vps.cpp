/*
*   4949¹ø - ±ÕÇüÀâÈù ¼¼»ó
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string solution(string str) {
    string answer = "";
    stack<char> stack;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(' || str[i] == '[') {
            stack.push(str[i]);
        }
        else if (str[i] == ')') {
            if (!stack.empty()) {
                if (stack.top() == '(') {
                    stack.pop();
                }
                else {
                    return answer = "no";
                }
            }
            else {
                return answer = "no";
            }
        }
        else if (str[i] == ']') {
            if (!stack.empty()) {
                if (stack.top() == '[') {
                    stack.pop();
                }
                else {
                    return answer = "no";
                }
            }
            else {
                return answer = "no";
            }
        }
    }

    if (stack.empty()) {
        return answer = "yes";
    }
    else {
        return answer = "no";
    }
}

int main() {

    string str = "";

    while (true) {
        getline(cin, str);

        if (str.compare(".") != 0) {
            cout << solution(str) << "\n";
            str.clear();
        }
        else {
            break;
        }
    }

    return 0;
}