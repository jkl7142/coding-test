/* 
    오아시스 재결합
*/

#include <iostream>
#include <stack>

using namespace std;

int n;
long long ans;

int main() {

    cin >> n;

    stack<pair<int, int>> s;
    
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        int cnt = 1;
        while (!s.empty() && s.top().first <= h) {
            // 바로 이전에 같은 키를 가진 사람들과 쌍을 이룸
            ans += s.top().second;
            // 같은 키면 2명으로 스택에 푸시하기 위함
            if (s.top().first == h)
                cnt += s.top().second;

            s.pop();
        }

        // 이전에 가장 큰 사람과 쌍을 이룸
        if (!s.empty())
            ans++;

        s.push({h, cnt});
    }

    cout << ans;

    return 0;
}