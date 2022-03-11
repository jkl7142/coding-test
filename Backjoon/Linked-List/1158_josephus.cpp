#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	vector<int> josephus;

	for (int i = 1; i <= n; i++) {
		josephus.push_back(i);
	}

	vector<int>::iterator cur = josephus.begin();

	cout << "<";

	while (!josephus.empty()) {
		for (int i = 1; i < k; i++) {
			if (cur + 1 == josephus.end())
				cur = josephus.begin();
			else
				cur++;
		}

		cout << *cur;
		cur = josephus.erase(cur);
		if (cur == josephus.end())
			cur = josephus.begin();

		if (!josephus.empty())
			cout << ", ";
		else
			cout << ">\n";
	}

	return 0;
}