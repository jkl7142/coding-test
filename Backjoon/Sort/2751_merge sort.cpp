/*
*   2750�� - �� �����ϱ� 2
*  �պ� ���� ����
*/

#include <iostream>
#include <vector>

using namespace std;

// �պ�
vector<int> merge(vector<int> leftNumbers, vector<int> rightNumbers) {
    vector<int> merged;

    vector<int>::iterator left = leftNumbers.begin();
    vector<int>::iterator right = rightNumbers.begin();

    while (left != leftNumbers.end() && right != rightNumbers.end()) {
        if (*left < *right) {
            merged.push_back(*left);
            left++;
        }
        else {
            merged.push_back(*right);
            right++;
        }
    }

    if (left != leftNumbers.end()) {
        for (; left != leftNumbers.end(); left++)
            merged.push_back(*left);
    }
    else {
        for (; right != rightNumbers.end(); right++)
            merged.push_back(*right);
    }

    return merged;
}

// ����
vector<int> mergeSort(vector<int> numbers) {
    if (numbers.size() > 1) {
        int mid = numbers.size() / 2;
        vector<int> left = mergeSort(vector<int>(numbers.begin(), numbers.begin() + mid));
        vector<int> right = mergeSort(vector<int>(numbers.begin() + mid, numbers.end()));

        return merge(left, right);
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

    for (auto r : mergeSort(numbers)) {
        cout << r << "\n";
    }

    return 0;
}