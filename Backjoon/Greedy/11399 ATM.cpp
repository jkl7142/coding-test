/*
*   11399¹ø - ATM
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int>& people) {
    int answer = 0;

    sort(people.begin(), people.end());
    vector<int> wait(people);

    for (int i = 0; i < people.size(); i++) {
        int cur_time = people[i];
        answer += wait[i];

        for (int j = i; j < people.size(); j++) {
            wait[j] += cur_time;
        }
    }

    return answer;
}

int main() {

    int n;
    cin >> n;
    vector<int> people;

    for (int i = 0; i < n; i++) {
        int time;
        cin >> time;

        people.push_back(time);
    }

    cout << solution(people) << "\n";

    return 0;
}