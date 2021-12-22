/*
*   13305번 - 주유소
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<long long> distances, vector<long long> stations) {
    long long answer = 0;
    long long price = stations[0];

    for (int i = 0; i < n - 1; i++) {
        long long one_distance = distances[i];
        answer += price * one_distance;

        long long next_price = stations[i + 1];
        price = min(price, next_price);
    }

    return answer;
}

int main() {

    int n;
    cin >> n;
    vector<long long> distances;
    vector<long long> stations;

    for (int i = 0; i < n - 1; i++) {
        long long dist;
        cin >> dist;

        distances.push_back(dist);
    }

    for (int i = 0; i < n; i++) {
        long long stat;
        cin >> stat;
        stations.push_back(stat);
    }

    cout << solution(n, distances, stations) << "\n";

    return 0;
}