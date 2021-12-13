/*
*   10814번 - 나이순 정렬
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}

void solution(vector<pair<int, string>>& users) {
    stable_sort(users.begin(), users.end(), cmp);
}

int main() {

    int n;
    cin >> n;

    vector<pair<int, string>> users;

    for (int i = 0; i < n; i++) {
        int age;
        string name;
        cin >> age >> name;

        users.push_back(make_pair(age, name));
    }
    
    solution(users);

    for (auto user : users) {
        cout << user.first << " " << user.second << "\n";
    }

    return 0;
}