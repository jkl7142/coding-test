/*
*   10828¹ø - ½ºÅÃ
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solution(vector<string> commands) {
    stack<string> stack;

    for (int i = 0; i < commands.size(); i++) {
        string command = commands[i];

        if (command == "push") {
            i++;
            command = commands[i];
            stack.push(command);
        }
        else if (command == "pop") {
            if (!stack.empty()) {
                cout << stack.top() << "\n";
                stack.pop();
            }
            else {
                cout << -1 << "\n";
            }
        }
        else if (command == "size") {
            cout << stack.size() << "\n";
        }
        else if (command == "empty") {
            cout << stack.empty() << "\n";
        }
        else {  // "top"
            if (!stack.empty()) {
                cout << stack.top() << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> commands;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        commands.push_back(command);
        
        if (command == "push") {
            string num;
            cin >> num;

            commands.push_back(num);
        }
    }

    solution(commands);
}