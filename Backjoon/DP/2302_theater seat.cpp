/*
    2302 - ���� �¼�
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 41

int n, m, ans = 1;
int vips[MAX_N];
int dp[MAX_N];    // ���ӵ� �ڸ��� ������ i���� �� ���� �� �ִ� ����� ��

int main() {

    cin >> n >> m;

    for (int i = 1; i <= m; i++)
        cin >> vips[i];

    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    for (int i = 1; i <= m; i++)
        // �� ���� ũ���� �Ǻ���ġ ������ �����ؼ� ��
        ans *= dp[vips[i] - vips[i - 1] - 1];
    // ������ vip���� N������ ���� ��
    ans *= dp[n - vips[m]];

    cout << ans;

    return 0;
}