/*
*   11047¹ø - µ¿Àü 0
*/

#include <iostream>
#include <vector>

using namespace std;

int solution(int& k, vector<int>& coins) {
    int answer = 0;
    int idx = coins.size();
    
    while (idx > 0) {
        idx--;
        
        if (k >= coins[idx]) {
            k -= coins[idx];
            idx = coins.size();
            answer++;
        }
    }

    return answer;
}

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> coins;

    for (int i = 0; i < n; i++) {
        int coin;
        cin >> coin;

        coins.push_back(coin);
    }

    cout << solution(k, coins) << "\n";

    return 0;
}