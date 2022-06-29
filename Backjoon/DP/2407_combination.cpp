/*
    2407 - 조합
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_N = 101;

int n, m;
string dp[MAX_N][MAX_N];

string sum(string c1, string c2) {
    int ret = 0;
    string result;

    while (!c1.empty() || !c2.empty() || ret) {
        if (!c1.empty()) {
            ret += c1.back() - '0';
            c1.pop_back();
        }
        if (!c2.empty()) {
            ret += c2.back() - '0';
            c2.pop_back();
        }

        result.push_back((ret % 10) + '0');
        ret /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

string comb(int n, int r) {
    if (r == 0 || n == r)
        return "1";

    if (dp[n][r] != "")
        return dp[n][r];

    return dp[n][r] = sum(comb(n - 1, r - 1), comb(n - 1, r));
}

int main() {
    
    cin >> n >> m;

    cout << comb(n, m);

    return 0;
}