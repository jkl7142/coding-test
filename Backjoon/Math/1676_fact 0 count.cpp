/*
*   1676번 - 팩토리얼 0의 개수
*/

#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i = 1; i <= n; i++) {
        int tmp = i;

        while (tmp) {
            if (tmp % 5 == 0) {
                answer++;
                tmp /= 5;
            }
            else {
                break;
            }
        }
    }

    return answer;
}

int main() {

    int n;
    cin >> n;

    cout << solution(n) << "\n";

    return 0;
}