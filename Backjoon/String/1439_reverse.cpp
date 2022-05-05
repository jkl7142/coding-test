/*
    1439 - 뒤집기
*/

#include <iostream>
#include <string>

using namespace std;

int ans, sSize;
string str;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    sSize = str.size();

    for (int i = 0; i < sSize; i++)
        if (str[i] != str[i + 1])
            ans++;
    
    if (ans == 0)
        cout << ans;
    else
        cout << ans / 2;

    return 0;
}