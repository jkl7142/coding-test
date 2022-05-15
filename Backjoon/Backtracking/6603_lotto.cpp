/*
    6603 - 로또
*/

#include <iostream>
#include <vector>

using namespace std;

const int MAX_K = 50;

int k, num;
vector<int> nums;
vector<int> lotto(6);

void init() {
    nums.clear();
}

void dfs(int cnt, int cur) {
    if (cnt == 6) {
        for (int i = 0; i < 6; i++) {
            cout << lotto[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = cur; i < k; i++) {
        lotto[cnt] = nums[i];
        dfs(cnt + 1, i + 1);
    }
}

int main() {

    while (true) {
        cin >> k;

        if (k == 0)
            break;

        init();

        for (int i = 0; i < k; i++) {
            cin >> num;
            nums.push_back(num);
        }

        dfs(0, 0);

        cout << "\n";
    }

    return 0;
}