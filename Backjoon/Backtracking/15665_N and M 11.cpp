/*
    15665번 - N과 M (11)
*/

#include <iostream>
#include <algorithm>

#define MAX_N 9
#define MAX_NUM 10'000

using namespace std;

int n, m;
int num[MAX_N];
int idxArr[MAX_N];
bool check[MAX_NUM];
int cnt;    // 중복되지 않는 숫자의 개수

void dfs(int idx) {
    if (idx == m) {
        for (int i = 0; i < m; i++) {
            cout << num[idxArr[i]] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        idxArr[idx] = i;
        dfs(idx + 1);
    }
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> num[cnt];
        if (check[num[cnt]])
            continue;
        
        check[num[cnt]] = true;
        cnt++;
    }

    n = cnt;

    sort(num, num + n);

    dfs(0);

    return 0;
}