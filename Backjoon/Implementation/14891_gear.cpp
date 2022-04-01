/*
    14891 - ��Ϲ���
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int k, ans;
string gear[4]; // 12�ú��� �ð����

void rotateGear(int g, int dir) {
    int dirs[4] = {};
    dirs[g] = dir;

    // 1. �������� ȸ�� ����
    int idx = g;
    // ���� ����� 9�� �κа� ���� ����� 3�� �κ� ��
    while (idx > 0 && gear[idx][6] != gear[idx - 1][2]) {
        dirs[idx - 1] = -dirs[idx]; // ������ �ݴ� ���� ó��
        idx--;
    }

    // 2. ���������� ȸ�� ����
    idx = g;
    while (idx < 3 && gear[idx][2] != gear[idx + 1][6]) {
        dirs[idx + 1] = -dirs[idx];
        idx++;
    }

    for (int i = 0; i < 4; i++) {
        // �ð� �����̸� gear[i][7]�� 12�÷�
        if (dirs[i] == 1)
            rotate(gear[i].begin(), gear[i].begin() + 7, gear[i].end());
        // �ݽð� �����̸� gear[i][1]�� 12�÷�
        if (dirs[i] == -1)
            rotate(gear[i].begin(), gear[i].begin() + 1, gear[i].end());
        
        // dirs[i] == 0 �̸� ����
    }
}

int main() {

    for (int i = 0; i < 4; i++)
        cin >> gear[i];

    cin >> k;
    for (int i = 0; i < k; i++) {
        int g, dir;
        cin >> g >> dir;

        rotateGear(g - 1, dir);
    }

    for (int i = 0; i < 4; i++) {
        if (gear[i][0] == '1')
            ans += (1 << i);
    }
    
    cout << ans;

    return 0;
}