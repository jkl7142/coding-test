/*
    12101 - 1, 2, 3 ¥ı«œ±‚ 2
*/

#include <iostream>

using namespace std;

#define MAX_N 11

int n, k, cnt;
int ans[MAX_N];
bool finish = false;

void dfs(int idx, int sum) {
    if (sum > n) return;
    
    if (sum == n) {
        cnt++;

        if (cnt == k) {
            finish = true;

            for (int i = 0; i < idx; i++) {
                if (i != idx - 1)
                    cout << ans[i] << "+";
                else
                    cout << ans[i];
            }
            return;
        }
    }

    for (int i = 1; i < 4; i++) {
        if (!finish) {
            ans[idx] = i;
            dfs(idx + 1, sum + i);
        }
        else 
            return;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    dfs(0, 0);

    if (cnt < k)
        cout << "-1";

    return 0;
}