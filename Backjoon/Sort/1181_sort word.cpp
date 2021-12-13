/*
*   1181번 - 단어 정렬
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool cmp(string a, string b) {
    if (a.length() == b.length())
        return a < b;
    
    return a.length() < b.length();
}

void solution(vector<string>& words) {
    sort(words.begin(), words.end(), cmp);
    words.erase(unique(words.begin(), words.end()), words.end());
}

int main() {

    int n;
    cin >> n;

    vector<string> words;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        words.push_back(str);
    }
    
    solution(words);

    for (auto word : words) {
        cout << word << "\n";
    }

    return 0;
}