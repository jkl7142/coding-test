/*
*   14888번 - 연산자 끼워넣기
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;
vector<int> opers(4);
int maxValue = -2147483648;
int minValue = 2147483647;

void solution(int sum, int idx, int n) {
    if (idx == n) {
        if (sum > maxValue)
            maxValue = sum;
        if (sum < minValue)
            minValue = sum;

        return;
    }

    for (int i = 0; i < 4; i++) {
        if (opers[i] > 0) {
            opers[i]--;
            if (i == 0)
                solution(sum + nums[idx], idx + 1, n);
            else if (i == 1)
                solution(sum - nums[idx], idx + 1, n);
            else if (i == 2)
                solution(sum * nums[idx], idx + 1, n);
            else
                solution(sum / nums[idx], idx + 1, n);

            opers[i]++;
        }
    }
    return;
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    for (int i = 0; i < 4; i++) {
        cin >> opers[i];
    }

    solution(nums[0], 1, n);

    cout << maxValue << "\n" << minValue << "\n";

    return 0;
}