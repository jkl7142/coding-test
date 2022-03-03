/* 
    6198번 - 옥상 정원 꾸미기
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
long long ans;

int main() {

    cin >> n;

    stack<long long> s;
    
    for (int i = 0; i < n; i++) {
        long long h;
        cin >> h;

        while (!s.empty() && s.top() <= h)
            s.pop();

        ans += s.size();
        s.push(h);
    }

    cout << ans << "\n";

    return 0;
}