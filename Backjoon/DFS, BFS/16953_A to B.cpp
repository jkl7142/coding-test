/*
    16953 - A -> B
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_A = 1'000'000;

long long a, b;
int ans = MAX_A;

void dfs(long long n, int cnt) {
    if (n > b)
        return;
    if (n == b) {
        ans = min(ans, cnt);
        return;
    }

    dfs(n * 2, cnt + 1);
    dfs(n * 10 + 1, cnt + 1);
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    dfs(a, 1);

    if (ans == MAX_A)
        cout << -1;
    else
        cout << ans;

    return 0;
}