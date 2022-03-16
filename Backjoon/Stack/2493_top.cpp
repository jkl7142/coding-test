/* 
    2493번 - 탑
 */

#include <iostream>
#include <stack>
#include <vector>

// 풀이 1. 배열 사용 (시간초과)
/* 
#define MAX_N 500001

using namespace std;

int n;
int heights[MAX_N];

int main() {

    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> heights[i];

        for (int j = i; j >= 0; j--) {
            if (j == 0 || i == 1) {
                cout << "0 ";
                break;
            }
            else if (heights[j - 1] > heights[i]) {
                cout << j - 1 << " ";
                break;
            }
        }
    }

    return 0;
}
 */

// 풀이 2. 스택 사용

#define MAX_H 100000001

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	stack<pair<int, int>> tower;

	tower.push(make_pair(MAX_H, 0));
	for (int i = 1; i <= n; i++) {
		int h;
		cin >> h;

		while (tower.top().first < h)
			tower.pop();

		cout << tower.top().second << " ";
		
		tower.push(make_pair(h, i));
	}

	return 0;
}
