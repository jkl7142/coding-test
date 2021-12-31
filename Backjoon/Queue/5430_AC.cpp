/*
*   5430¹ø - AC
*/

#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<string> parseDeq(string& str, string sep) {
    deque<string> parsed;
    size_t prev = 1, curr = str.find(sep);
    
    while (curr != string::npos) {
        string subStr = str.substr(prev, curr - prev);
        parsed.push_back(subStr);
        prev = curr + 1;

        curr = str.find(sep, prev);
    }

    if (parsed.empty() && str.length() == 2) {
        return parsed;
    }

    curr = str.find("]");
    parsed.push_back(str.substr(prev, curr - prev));

    return parsed;
}

string solution(string func, int n, string arr) {
    string answer = "";
    deque<string> deque = parseDeq(arr, ",");
    bool reverse = false;

    for (auto c : func) {
        if (c == 'R') {
            reverse = !reverse;
        }
        else {  // 'D'
            if (reverse) {  // ¿ª¼ø
                if (deque.empty()) {
                    return answer = "error";
                }
                else {
                    deque.pop_back();
                }
            }
            else {
                if (deque.empty()) {
                    return answer = "error";
                }
                else {
                    deque.pop_front();
                }
            }
        }
    }

    if (reverse) {
        answer += "[";
        while (!deque.empty()) {
            answer += deque.back();
            deque.pop_back();
            if (!deque.empty())
                answer += ",";
        }
        answer += "]";
    }
    else {
        answer += "[";
        while (!deque.empty()) {
            answer += deque.front();
            deque.pop_front();
            if (!deque.empty())
                answer += ",";
        }
        answer += "]";
    }

    return answer;
}

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string func, arr;
        int n;
        cin >> func >> n >> arr;

        cout << solution(func, n, arr) << "\n";
    }

    return 0;
}