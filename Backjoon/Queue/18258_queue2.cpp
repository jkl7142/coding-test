/*
*   18258¹ø - Å¥ 2
*/

#include <iostream>
#include <string>
#include <queue>

using namespace std;

void solution(vector<string> commands) {
    queue<string> queue;

    for (int i = 0; i < commands.size(); i++) {
        string command = commands[i];

        if (command == "push") {
            i++;
            command = commands[i];
            queue.push(command);
        }
        else if (command == "pop") {
            if (!queue.empty()) {
                cout << queue.front() << "\n";
                queue.pop();
            }
            else {
                cout << -1 << "\n";
            }
        }
        else if (command == "size") {
            cout << queue.size() << "\n";
        }
        else if (command == "empty") {
            cout << queue.empty() << "\n";
        }
        else if (command == "front") {
            if (!queue.empty()) {
                cout << queue.front() << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
        else {  // "back"
            if (!queue.empty()) {
                cout << queue.back() << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
    }
}

int main() {
    
    cin.tie(0);
    cin.sync_with_stdio(0);
    
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

    return 0;
}