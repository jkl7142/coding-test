/*
*   12015번 - 가장 긴 증가하는 부분 수열 2
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int answer = 0;

void solution(vector<int>& sequence) {
    vector<int> subSequence;
    int sSize = sequence.size();

    subSequence.push_back(sequence[0]);
    for (int i = 1; i < sSize; i++) {
        if (subSequence.back() < sequence[i])
            subSequence.push_back(sequence[i]);
        else {
            auto it = lower_bound(subSequence.begin(), subSequence.end(), sequence[i]);
            *it = sequence[i];
        }
    }

    answer = subSequence.size();
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

    solution(sequence);

    cout << answer << "\n";

    return 0;
}