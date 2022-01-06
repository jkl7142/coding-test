/*
*   10816번 - 숫자 카드 2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int>& cards, vector<int>& finds) {
    int fSize = finds.size();
    int cSize = cards.size();
    vector<int> answer(fSize, 0);

    for (int i = 0; i < fSize; i++) {
        int numCount = upper_bound(cards.begin(), cards.end(), finds[i])
                        - lower_bound(cards.begin(), cards.end(), finds[i]);

        answer[i] = numCount;
    }

    return answer;
}

int main() {

    int n;
    cin >> n;
    vector<int> cards;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        cards.push_back(num);
    }

    int m;
    cin >> m;
    vector<int> finds;

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        finds.push_back(num);
    }

    sort(cards.begin(), cards.end());

    for (auto num : solution(cards, finds)) {
        cout << num << " ";
    }

    return 0;
}