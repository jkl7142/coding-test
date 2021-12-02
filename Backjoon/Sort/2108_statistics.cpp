/*
*   2108번 - 통계학
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

void solution(int n, vector<int> v) {
    int aver, medi, mode, rang;

    // 1.
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    aver = round(static_cast<double>(sum) / static_cast<double>(n));
    
    cout << aver << endl;

    // 2.
    vector<int> tmps(v);
    sort(tmps.begin(), tmps.end(), less<int>());

    medi = tmps[ceil(v.size()/2)];

    cout << medi << endl;

    // 3.
    if (n == 1)
        mode = v[0];
    else {
        int tmp = 0;
        map<int, int> map;
        vector<int> modes;
        for (int i = 0; i < n; i++) {
            map[v[i]]++;
        
            if (tmp < map[v[i]]) {
                tmp = map[v[i]];
            }

            if (i == n - 1) {
                for (int j = 0; j < n; j++) {
                    if (tmp == map[v[j]]) {
                        modes.push_back(v[j]);
                    }
                }
            }
        }

        sort(modes.begin(), modes.end(), less<int>());
        unique(modes.begin(), modes.end());
        
        mode = modes[1];
    }
    
    cout << mode << endl;

    // 4.
    int maxV, minV;
    
    maxV = *max_element(v.begin(), v.end());
    minV = *min_element(v.begin(), v.end());

    rang = maxV - minV;

    cout << rang << endl;
}

int main() {

    int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    solution(n, v);

    return 0;
}