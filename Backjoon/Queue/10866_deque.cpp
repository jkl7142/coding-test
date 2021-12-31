/*
*   10866¹ø - µ¦
*/

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {

    cin.tie(0);
    cin.sync_with_stdio(0);

    int n;
    cin >> n;
    deque<int> deque;

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "push_front") {
            int num;
            cin >> num;

            deque.push_front(num);
        }
        else if (command == "push_back") {
            int num;
            cin >> num;

            deque.push_back(num);
        }
        else if (command == "pop_front") {
            if (!deque.empty()) {
                cout << deque.front() << "\n";
                deque.pop_front();
            }
            else
                cout << -1 << "\n";
        }
        else if (command == "pop_back") {
            if (!deque.empty()) {
                cout << deque.back() << "\n";
                deque.pop_back();
            }
            else
                cout << -1 << "\n";
        }
        else if (command == "size") {
            cout << deque.size() << "\n";
        }
        else if (command == "empty") {
            cout << deque.empty() << "\n";
        }
        else if (command == "front") {
            if (!deque.empty())
                cout << deque.front() << "\n";
            else
                cout << -1 << "\n";
        }
        else {  // "back"
            if (!deque.empty())
                cout << deque.back() << "\n";
            else
                cout << -1 << "\n";
        }
    }

    return 0;
}