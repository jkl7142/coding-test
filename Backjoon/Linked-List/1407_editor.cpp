#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    string str;
    cin >> str;
    int m;
    cin >> m;

    list<char> linkedList;
    for (char c : str) {
        linkedList.push_back(c);
    }

    list<char>::iterator cur = linkedList.end();

    for (int i = 0; i < m; i++) {
		char com;
		cin >> com;

		if (com == 'L') {
			if (cur != linkedList.begin()) {
				cur--;
			}
		}
		else if (com == 'D') {
			if (cur != linkedList.end()) {
				cur++;
			}
		}
		else if (com == 'B') {
			if (cur != linkedList.begin()) {
				cur--;
				cur = linkedList.erase(cur);
			}
		}
		else {	// com == 'P' $
			char c;
			cin >> c;

			cur = linkedList.insert(cur, c);
			cur++;
		}
	}

    for (auto it = linkedList.begin(); it != linkedList.end(); it++) {
		cout << *it;
	}

    return 0;
}