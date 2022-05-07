/*
    1786 - 찾기
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX_L 1'000'001

string text, pattern;
vector<int> ans;

vector<int> getPi(string p) {
    int pSize = p.size();
    vector<int> pi(pSize, 0);

    int idx = 0;
    for (int i = 1; i < pSize; i++) {   
        while (idx > 0 && p[i] != p[idx])
            idx = pi[idx - 1];

        if (p[i] == p[idx])
            pi[i] = ++idx;
    }

    return pi;
}

void kmp(string t, string p) {
    int tSize = t.size(), pSize = p.size();
    int matched = 0;

    vector<int> pi = getPi(pattern);

    for (int i = 0; i < tSize; i++) {
        while (matched > 0 && t[i] != p[matched])
            matched = pi[matched - 1];
        
        if (t[i] == p[matched]) {
            if (matched == pSize - 1) {
                ans.push_back(i - pSize + 2);
                matched = pi[matched];
            }
            else
                matched++;
        }
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    getline(cin, text);
    getline(cin, pattern);

    kmp(text, pattern);

    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i << " ";
    }

    return 0;
}