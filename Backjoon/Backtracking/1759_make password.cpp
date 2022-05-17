/*
    1759 - 암호 만들기
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_L = 16;

int l, c;
char alpha[MAX_L];
char password[MAX_L];

bool isPass() {
    int cnt = 0;
    for (int i = 0; i < l; i++) {
        if (password[i] == 'a' ||
            password[i] == 'e' ||
            password[i] == 'i' ||
            password[i] == 'o' ||
            password[i] == 'u')
            cnt++;
    }

    if (cnt >= 1 && l - cnt >= 2)
        return true;
    return false;
}

void dfs(int idx, int cur) {
    if (idx == l) {
        if (isPass()) {
            for (int i = 0; i < l; i++) {
                cout << password[i];
            }
        cout << "\n";
        }
        return;
    }

    for (int i = cur; i < c; i++) {
        password[idx] = alpha[i];
        dfs(idx + 1, i + 1);
    }
}

int main() {

    cin >> l >> c;

    for (int i = 0; i < c; i++) {
        cin >> alpha[i];
    }

    sort(alpha, alpha + c);

    dfs(0, 0);

    return 0;
}