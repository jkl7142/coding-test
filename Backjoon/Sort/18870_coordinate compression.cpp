/*
*   18870번 - 좌표 압축
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solution(vector<int>& coordinates) {
    vector<int> sorted(coordinates);
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    for (int i = 0; i < coordinates.size(); i++) {
        cout << lower_bound(sorted.begin(), sorted.end()
                , coordinates[i]) - sorted.begin() << " ";
    }
}

int main() {

    int n;
    cin >> n;

    vector<int> coordinates;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        coordinates.push_back(x);
    }
    
    solution(coordinates);

    return 0;
}