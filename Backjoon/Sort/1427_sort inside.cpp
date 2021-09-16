/*
*   1427번 - 소트인사이드
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int solution(int n) {
    int answer = 0;
    string str = to_string(n);
    sort(str.begin(), str.end(), greater<int>());
    
    answer = stoi(str);

    return answer;
}

int main() {

    int n;
    cin >> n;

    cout << solution(n) << "\n";

    return 0;
}