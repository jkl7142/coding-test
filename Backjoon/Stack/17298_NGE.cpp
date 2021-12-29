/*
*   17298번 - 오큰수
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(int n, vector<int>& sequence) {
    vector<int> answer(n);
    stack<int> stack;

    for (int i = n - 1; i >= 0; i--) {
        while (!stack.empty() && stack.top() <= sequence[i]) {
            stack.pop();
        }

        if (stack.empty())
            answer[i] = -1;
        else
            answer[i] = stack.top();

        stack.push(sequence[i]);
    }

    return answer;
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

    for (int r : solution(n, sequence)) {
        cout << r << " ";
    }

    return 0;
}