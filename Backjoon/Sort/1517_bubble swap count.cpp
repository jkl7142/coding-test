#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long answer = 0;

void mergeSort(int begin, int end, vector<int>& A) {
    int mid = (begin + end) / 2;
    int left = begin;
    int right = mid + 1;
    vector<int> merged;

    if (begin == end)
        return;

    mergeSort(begin, mid, A);
    mergeSort(mid + 1, end, A);

    while (left <= mid && right <= end) {
        if (A[left] <= A[right])
            merged.push_back(A[left++]);
        else {
            merged.push_back(A[right++]);
            answer += (mid + 1 - left);
        }
    }

    while (left <= mid)
        merged.push_back(A[left++]);
    while (right <= end)
        merged.push_back(A[right++]);
    for (int i = begin, j = 0; i <= end; ++i, ++j)
		A[i] = merged[j];
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    mergeSort(0, N - 1, A);

    cout << answer;
}