/*
*   6549�� - ������׷����� ���� ū ���簢��
*   : ���׸�Ʈ Ʈ���� Ȱ���� Ǯ��
*   (������ Ȱ���� Ǯ�� 1725��)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_VALUE 2147483647
long long answer = 0;
vector<int> segmentTree(1000001, 0);
vector<long long> histogram;

int initTree(int node, int start, int end) {
    if (start == end) return segmentTree[node] = start;
    int mid = (start + end) / 2;
    int left = initTree(2 * node, start, mid);
    int right = initTree(2 * node + 1, mid + 1, end);

    if (histogram[left] < histogram[right]) {
        return segmentTree[node] = left;
    }
    else {
        return segmentTree[node] = right;
    }
}

int query(int node, int start, int end, int left, int right) {
    if (end < left || right < start)  // ã�� ������ ��� ������ ��ġ�� ���� ��
        return MAX_VALUE;
    if (left <= start && end <= right) // ã�� ������ ��� ������ ���Ե� ��
        return segmentTree[node];
    
    int mid = (start + end) / 2;
    int leftIdx = query(2 * node, start, mid, left, right);
    int rightIdx = query(2 * node + 1, mid + 1, end, left, right);

    // ã�� ������ �κ������� ��ĥ ��
    if (leftIdx == MAX_VALUE)
        return rightIdx;
    else if (rightIdx == MAX_VALUE)
        return leftIdx;
    else {
        if (histogram[leftIdx] < histogram[rightIdx])
            return leftIdx;
        else
            return rightIdx;
    }
}

void solution(int n, int left, int right) {
    if (left > right)
        return;

    // ���� ���� �ּҰ� �ε��� ã��
    int idx = query(1, 0, n - 1, left, right);

    answer = max(answer, histogram[idx] * (right - left + 1));

    // �ε��� ���� ���ʰ� ������ Ž��
    solution(n, left, idx - 1);
    solution(n, idx + 1, right);
}

int main() {

    while (true) {
        int n;
        cin >> n;

        if (n == 0)
            return 0;

        for (int i = 0; i < n; i++) {
            long long height;
            cin >> height;

            histogram.push_back(height);
        }

        initTree(1, 0, n - 1);
        solution(n, 0, n - 1);

        cout << answer << "\n";

        answer = 0;
        histogram.clear();
        segmentTree.clear();
        segmentTree.resize(1000001);
    }

    return 0;
}