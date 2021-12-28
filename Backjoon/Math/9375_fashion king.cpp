/*
*   9375�� - �мǿ� ���غ�
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
        map<string, int> clothes;   // �ǻ�����, ����
        int answer = 1;

        for (int j = 0; j < n; j++) {
            string name, type;
            cin >> name >> type;

            if (clothes.find(type) == clothes.end())
                clothes.insert({type, 1});
            else
                clothes[type]++;
        }

        // �� ����� �� = �ǻ� ������ 1�� ������ ��� ����
        // (�� �������� �ƿ� �������� �ʴ� ��쵵 �����Ƿ� + 1)
        for (auto it = clothes.begin(); it != clothes.end(); it++) {
            answer *= it->second + 1;
        }

        // �ƹ��͵� ���� ���� ��츦 ����
        cout << answer - 1 << "\n";
    }

    return 0;
}