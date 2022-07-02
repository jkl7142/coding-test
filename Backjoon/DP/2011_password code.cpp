/*
    2011 - 암호코드
*/

#include <iostream>
#include <string>

using namespace std;

const int MAX_L = 5001;
const int MOD = 1'000'000;

string str;
int len;
long long dp[MAX_L];

int main() {

    cin >> str;

    len = str.size();
    str.insert(0, " ");

    dp[0] = 1;
    for (int i = 1; i <= len; i++) {
        int c = str[i] - '0';
        if (0 < c)
            dp[i] = (dp[i] + dp[i - 1]) % MOD;

        if (i == 1 || str[i - 1] == '0')
            continue;

        c = (str[i - 1] - '0') * 10 + (str[i] - '0');
        if (10 <= c && c <= 26)
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }

    cout << dp[len] << "\n";

    return 0;
}