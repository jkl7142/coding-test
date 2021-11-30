/*
*   1436번 - 영화감독 숌
*/

#include <iostream>
#include <string>

using namespace std;

int solution(int n) {
    int answer = 0;
    int title = 666;

    while (true) {
        string temp = to_string(title);

        if (temp.find("666") != string::npos) {
            answer++;
        }

        if (answer == n)
            break;
        else {
            title++;
        }
    }

    return title;
}

int main() {
    int n;
    cin >> n;

    cout << solution(n) << "\n";

    return 0;
}