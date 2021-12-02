/*
*   10989번 - 수 정렬하기 3
*   카운팅 정렬 구현
*/

#include <iostream>
#include <vector>

using namespace std;

//  카운팅 정렬 함수
vector<int> countingSort(int n, int maxNum, vector<int> numbers) {
    vector<int> result(n);
    vector<int> count(maxNum + 1, 0);

    for (int i = 0; i < n; i++) {
        count[numbers[i]]++;

        if (numbers[i] > maxNum)
            maxNum = numbers[i];
    }

    for (int i = 1; i <= maxNum; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        count[numbers[i]]--;
        result[count[numbers[i]]] = numbers[i];
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers;
    int maxNum = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);

        if (num > maxNum)
            maxNum = num;
    }

    for (auto r : countingSort(n, maxNum, numbers)) {
        cout << r << "\n";
    }

    return 0;
}

/*
int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int maxNum = 0;
    vector<int> count(10001, 0);

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        count[num]++;

        if (num > maxNum)
            maxNum = num;
    }

    for (int i = 0; i <= maxNum; i++) {
        while (count[i] != 0) {
            cout << i << "\n";
            count[i]--;
        }
    }

    return 0;
}*/