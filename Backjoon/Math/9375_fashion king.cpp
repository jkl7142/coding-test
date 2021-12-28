/*
*   9375번 - 패션왕 신해빈
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        map<string, int> clothes;   // 의상종류, 개수
        int answer = 1;

        for (int j = 0; j < n; j++) {
            string name, type;
            cin >> name >> type;

            if (clothes.find(type) == clothes.end())
                clothes.insert({type, 1});
            else
                clothes[type]++;
        }

        // 총 경우의 수 = 의상 종류당 1개 선택을 모두 곱함
        // (한 종류에서 아예 선택하지 않는 경우도 있으므로 + 1)
        for (auto it = clothes.begin(); it != clothes.end(); it++) {
            answer *= it->second + 1;
        }

        // 아무것도 고르지 않은 경우를 제거
        cout << answer - 1 << "\n";
    }

    return 0;
}