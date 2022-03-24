/*
*   1780번 - 종이의 개수
*/

#include <iostream>
#include <vector>

using namespace std;

// 풀이 1

#define MAX_N 2188

int n;
int paper[MAX_N][MAX_N];
int mCnt, zCnt, oCnt;

void solution(int x, int y, int size) {
	int base = paper[y][x];

	for (int r = y; r < y + size; r++) {
		for (int c = x; c < x + size; c++) {
			if (c == x && r == y) {
				continue;
			}

			if (base != paper[r][c]) {
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						solution(x + (size / 3) * j, y + (size / 3) * i, size / 3);
					}
				}
				return;
			}
		}
	}

	if (base == -1)
		mCnt++;
	else if (base == 0)
		zCnt++;
	else
		oCnt++;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	solution(0, 0, n);

	cout << mCnt << "\n" << zCnt << "\n" << oCnt;

	return 0;
}

// 풀이 2
/*
vector<vector<int>> papers;
int nOne = 0, pOne = 0, zero = 0;

void solution(int y, int x, int size) {
    bool divide = false;
    int basedNum = papers[y][x];

    for (int row = y; row < y + size; row++) {
        for (int col = x; col < x + size; col++) {
            if (basedNum != papers[row][col]) {
                divide = true;
                break;
            }
        }
        if (divide)
            break;
    }

    if (divide) {
        size /= 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                solution(y + size * i, x + size * j, size);
            }
        }
    }
    else if (basedNum == -1) {
        nOne++;
    }
    else if (basedNum == 0) {
        zero++;
    }
    else {  // == 1
        pOne++;
    }
}

int main() {

    int n;
    cin >> n;
    papers = vector<vector<int>> (n, vector<int> (n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> papers[i][j];
        }
    }

    solution(0, 0, n);

    cout << nOne << "\n";
    cout << zero << "\n";
    cout << pOne << "\n";

    return 0;
}
*/