/*
*   12865번 - 배낭 문제
*   배낭에 넣을 수 있는 물건들의 가치 최댓값 구하기
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int k, vector<pair<int, int>> things) {
    int answer = 0;
    vector<vector<int>> DP(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++) {
        int currentWeight = things[i - 1].first;
        int currentValue = things[i - 1].second;

        for (int totalWeight = 1; totalWeight <= k; totalWeight++) {
            if (totalWeight < currentWeight) {
                DP[i][totalWeight] = DP[i - 1][totalWeight];
            }
            else {
                DP[i][totalWeight] = max(DP[i - 1][totalWeight],
                                        DP[i - 1][totalWeight - currentWeight] + currentValue);
            }
        }
    }

    answer = DP[n][k];
    return answer;
}

int main() {
    int N, K;   // N : 물건의 수, K : 최대 무게
    cin >> N >> K;
    vector<pair<int, int>> things;

    for (int i = 0; i < N; i++) {
        int W, V;   // W : 물건의 무게, V : 물건의 가치
        cin >> W >> V;
        things.push_back(make_pair(W, V));
    }

    cout << solution(N, K, things);

    return 0;
}