/*
*   2798¹ø - ºí·¢Àè
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> cards) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int sum = cards[i] + cards[j] + cards[k];
                if (sum <= m && sum > answer)
                    answer = sum;
            }
        }
    }

    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> cards;

    for (int i = 0; i < n; i++) {
        int card;
        cin >> card;

        cards.push_back(card);
    }

    cout << solution(n, m, cards);
}