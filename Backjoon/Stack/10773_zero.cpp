/*
*   10773? - ??
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// ?? 1. ?? ??

int main() {

	int k, ans = 0;
	cin >> k;

	stack<int> s;

	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		
		if (num != 0) {
			s.push(num);
		}
		else {
			s.pop();
		}
	}

	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}

	cout << ans << "\n";

	return 0;
}

// ?? 2. ??? ???? ??
/*
void solution(int n, vector<int>& v) {
    if (n == 0) {
        v.pop_back();
    }
    else {
        v.push_back(n);
    }
}

int main() {

    int k;
    cin >> k;

    int result = 0;
    vector<int> v;

    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;

        solution(n, v);
    }

    for (int i = 0; i < v.size(); i++) {
        result += v[i];
    }
    
    cout << result << endl;

    return 0;
}
*/