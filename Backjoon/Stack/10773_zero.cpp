/*
*   10773¹ø - Á¦·Î
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(int n, vector<int>& v) {
    if (n == 0) {
        v.pop_back();
    }
    else {
        v.push_back(n);
    }
}

int main() {

    int k;
    cin >> k;

    int result = 0;
    vector<int> v;

    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;

        solution(n, v);
    }

    for (int i = 0; i < v.size(); i++) {
        result += v[i];
    }
    
    cout << result << endl;

    return 0;
}