#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {

	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;

		list<char> linkedList;
		list<char>::iterator cur = linkedList.begin();
		
		for (char c : str) {
			if (c == '<') {
				if (cur != linkedList.begin())
					cur--;
			}
			else if (c == '>') {
				if (cur != linkedList.end())
					cur++;
			}
			else if (c == '-') {
				if (cur != linkedList.begin()) {
					cur--;
					cur = linkedList.erase(cur);
				}
			}
			else {
				cur = linkedList.insert(cur, c);
				cur++;
			}
		}

		for (auto it = linkedList.begin(); it != linkedList.end(); it++) {
			cout << *it;
		}
		cout << "\n";
	}

	return 0;
}