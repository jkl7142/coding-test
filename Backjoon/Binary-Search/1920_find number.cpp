/*
*   1920번 - 수 찾기
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool binary_search(int num, int start, int end, vector<int>& numbers) {
    if (start >= end) {
        return num == numbers[start];
    }

    int mid = (start + end) / 2;
    if (num == numbers[mid]) {
        return true;
    }
    else if (num < numbers[mid]) {
        return binary_search(num, start, mid, numbers);
    }
    else { // num > numbers[mid]
        return binary_search(num, mid + 1, end, numbers);
    }
}

void solution(vector<int>& numbers, vector<int>& finds) {
    int nSize = numbers.size();
    int fSize = finds.size();
    for (int i = 0; i < fSize; i++) {
        if (binary_search(finds[i], 0, nSize - 1, numbers))
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
}

int main() {

    int n, m;
    cin >> n;
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    cin >> m;
    vector<int> finds;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        finds.push_back(num);
    }

    sort(numbers.begin(), numbers.end());

    solution(numbers, finds);

    return 0;
}