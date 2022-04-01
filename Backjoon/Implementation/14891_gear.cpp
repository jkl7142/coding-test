/*
    14891 - 톱니바퀴
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int k, ans;
string gear[4]; // 12시부터 시계방향

void rotateGear(int g, int dir) {
    int dirs[4] = {};
    dirs[g] = dir;

    // 1. 왼쪽으로 회전 전파
    int idx = g;
    // 현재 기어의 9시 부분과 왼쪽 기어의 3시 부분 비교
    while (idx > 0 && gear[idx][6] != gear[idx - 1][2]) {
        dirs[idx - 1] = -dirs[idx]; // 현재의 반대 방향 처리
        idx--;
    }

    // 2. 오른쪽으로 회전 전파
    idx = g;
    while (idx < 3 && gear[idx][2] != gear[idx + 1][6]) {
        dirs[idx + 1] = -dirs[idx];
        idx++;
    }

    for (int i = 0; i < 4; i++) {
        // 시계 방향이면 gear[i][7]이 12시로
        if (dirs[i] == 1)
            rotate(gear[i].begin(), gear[i].begin() + 7, gear[i].end());
        // 반시계 방향이면 gear[i][1]이 12시로
        if (dirs[i] == -1)
            rotate(gear[i].begin(), gear[i].begin() + 1, gear[i].end());
        
        // dirs[i] == 0 이면 무시
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