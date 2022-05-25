/*
    13975 - 파일 합치기 3
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, k;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        long long ans = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        cin >> k;
        for (int i = 0; i < k; i++) {
            int file;
            cin >> file;
            pq.push(file);
        }

        while (pq.size() >= 2) {
            long long aFile = pq.top();
            pq.pop();
            long long bFile = pq.top();
            pq.pop();

            ans += aFile + bFile;
            pq.push(aFile + bFile);
        }

        cout << ans << "\n";
    }

    return 0;
}