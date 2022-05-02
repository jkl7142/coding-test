/*
    1764 - 듣보잡
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAX_N 500'001

int n, m;
vector<string> deud, deudbo;

bool binarySearch(int s, int e, string& str) {
    if (s > e)
        return false;

    int mid = (s + e) / 2;
    
    if (deud[mid] == str)
        return true;
    else if (deud[mid] > str)
        return binarySearch(s, mid - 1, str);
    else
        return binarySearch(mid + 1, e, str);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string jap;
        cin >> jap;
        deud.push_back(jap);
    }

    sort(deud.begin(), deud.end());

    for (int i = 0; i < m; i++) {
        string jap;
        cin >> jap;
        
        if (binarySearch(0, n - 1, jap))
            deudbo.push_back(jap);
    }

    sort(deudbo.begin(), deudbo.end());

    cout << deudbo.size() << "\n";
    for (string s : deudbo) {
        cout << s << "\n";
    }

    return 0;
}