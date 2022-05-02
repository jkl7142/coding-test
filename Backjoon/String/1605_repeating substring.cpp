/*
    1605 - 반복 부분문자열
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX_L 200'001
#define MOD 100'007

int l, ans;
string str;
int radix = 29;
int RM[MAX_L];
vector<int> hashTable[MOD];

bool check(int aIdx, int bIdx, int len) {
    for (int i = 0; i < len; i++)
        if (str[aIdx + i] != str[bIdx + i])
            return false;

    return true;
}

int hashing(int len) {
    int hash = 0;
    for (int i = 0; i < len; i++) {
        hash = (radix * hash + str[i]) % MOD;
    }
    return hash;
}

bool rabinKarp(int len) {
    for (int i = 0; i < MOD; i++) {
        hashTable[i].clear();
    }

    int hash = hashing(len);
    hashTable[hash].push_back(0);

    for (int i = len; i < l; i++) {
        hash = (hash + MOD - (RM[len - 1] * str[i - len]) % MOD) % MOD;
        hash = (radix * hash + str[i]) % MOD;

        if (hashTable[hash].size()) {
            for (int idx : hashTable[hash]) {
                if (check(idx, i - len + 1, len))
                    return true;
            }
        }

        hashTable[hash].push_back(i - len + 1);
    }

    return false;
}

void bSearch(int start, int end) {
    if (start > end)
        return;

    int mid = (start + end) / 2;
    
    if (rabinKarp(mid)) {
        ans = max(ans, mid);
        bSearch(mid + 1, end);
    }
    else {
        bSearch(start, mid - 1);
    }   
}

int main() {

    cin >> l;
    cin >> str;

    // RM 전처리
    RM[0] = 1;
    for (int i = 1; i < MAX_L; i++)
        RM[i] = (radix * RM[i - 1]) % MOD;

    bSearch(0, l);

    cout << ans;

    return 0;
}