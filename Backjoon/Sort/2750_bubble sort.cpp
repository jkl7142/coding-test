/*
*   2750번 - 수 정렬하기
*  버블 정렬 구현
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> bubbleSort(vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < numbers.size() - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]);
            }
        }
    }
    return numbers;
}

int main() {

    int n;
    cin >> n;
    vector<int> numbers;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    for (auto r : bubbleSort(numbers)) {
        cout << r << "\n";
    }

    return 0;
}