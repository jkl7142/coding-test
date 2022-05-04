/*
    1120 - 문자열
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int ans = 51, sSize;
string X, Y;

int main() {

    cin >> X >> Y;

    for (int i = 0; i <= Y.size() - X.size(); i++) {
        int cnt = 0;

        for (int j = 0; j < X.size(); j++) {
            if (X[j] != Y[j + i])
                cnt++;
        }

        ans = min(ans, cnt);
    }

    cout << ans;

    return 0;
}