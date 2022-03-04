/* 
    ���ƽý� �����
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
            // �ٷ� ������ ���� Ű�� ���� ������ ���� �̷�
            ans += s.top().second;
            // ���� Ű�� 2������ ���ÿ� Ǫ���ϱ� ����
            if (s.top().first == h)
                cnt += s.top().second;

            s.pop();
        }

        // ������ ���� ū ����� ���� �̷�
        if (!s.empty())
            ans++;

        s.push({h, cnt});
    }

    cout << ans;

    return 0;
}