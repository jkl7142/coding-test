/*
*   2751번 - 수 정렬하기 2
*  퀵 정렬 구현
*/

#include <iostream>
#include <vector>

using namespace std;

// 분할
int partition(int begin, int end, vector<int>& numbers) {
    int pivot = numbers[begin];
    int left = begin + 1;
    int right = end;

    while (left <= right) {
        for (;numbers[left] <= pivot && left <= end; left++);
        for (;numbers[right] >= pivot && right > begin; right--);
        if (left <= right) {
            swap(numbers[left], numbers[right]);
        }
        else {
            if (pivot > numbers[right]) {
                swap(numbers[begin], numbers[right]);
            }
        }
    }

    return right;
}

void quickSort(int begin, int end, vector<int>& numbers) {
    if (begin < end) {
        int pivot = partition(begin, end, numbers);

        quickSort(begin, pivot - 1, numbers);
        quickSort(pivot + 1, end, numbers);
    }
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

    quickSort(0, n - 1, numbers);

    for (auto r : numbers) {
        cout << r << "\n";
    }

    return 0;
}