/*
*   2750번 - 수 정렬하기
*  삽입 정렬 구현
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> insertionSort(vector<int>& numbers) {
    int j;
    int key;
    
    for (int i = 1; i < numbers.size(); i++) {
        key = numbers[i];

        for (j = i - 1; j >= 0; j--) {
            if (numbers[j] > key) {
                numbers[j + 1] = numbers[j];
            }
            else
                break;
        }
        numbers[j + 1] = key;
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

    for (auto r : insertionSort(numbers)) {
        cout << r << "\n";
    }

    return 0;
}