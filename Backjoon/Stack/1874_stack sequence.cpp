/*
*   1874번 - 스택 수열
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

vector<string> solution(int n, vector<int>& sequence) {
    vector<string> result;
    stack<int> stack;
    int count = 1;

    for (int i = 0; i < n; i++) {
        int num = sequence[i];

        if (count <= num) {
            for (int j = count; j <= num; j++) {
                stack.push(j);
                result.push_back("+");
            }

            count = num + 1;
        }

        if (stack.top() == num) {
            stack.pop();
            result.push_back("-");
        }
    }

    if (!stack.empty()) {
        return vector<string>({"NO"});
    }

    return result;
}

int main() {

    int n;
    cin >> n;
    vector<int> sequence;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        sequence.push_back(num);
    }

    for (auto r : solution(n, sequence)) {
        cout << r << "\n";
    }

    return 0;
}