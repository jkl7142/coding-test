/*
    10610 - 30
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string num;
int digits;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num;

    sort(num.begin(), num.end(), greater<int>());

    if (num[num.size() - 1] != '0') {
        cout << -1;
        return 0;
    }
    
    for (int i = 0; i < num.size() - 1; i++)
        digits += (int)num[i];

    if (digits % 3 == 0)
        cout << num;
    else
        cout << -1;

    return 0;
}