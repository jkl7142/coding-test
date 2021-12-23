/*
*   2981¹ø - °Ë¹®
*/

#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <algorithm>

using namespace std;

long long GCD(long long a, long long b) {
    long long answer = 0;

    while (b != 0) {
        long long temp = a % b;
        a = b;
        b = temp;
    }

    return answer = a;
}

set<long long> solution(vector<long long>& nums) {
    set<long long> result;
    long long temp = 1000000000;

    for (int i = 0; i < nums.size() - 1; i++) {
        nums[i] = abs(nums[i] - nums[i + 1]);
    }

    if (nums.size() == 2) {
        temp = nums[0];
    }
    else {
        for (int i = 0; i < nums.size() - 2; i++) {
            temp = min(temp, GCD(nums[i], nums[i + 1]));
        }
    }

    for (int i = 1; i * i <= temp; i++) {
        if (i == 1)
            result.insert(temp);
        else if (temp % i == 0) {
            result.insert(i);
            result.insert(temp / i);
        }
    }

    return result;
}

int main() {

    int n;
    cin >> n;
    vector<long long> nums;

    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;

        nums.push_back(num);
    }

    set<long long> result = solution(nums);
    for (set<long long>::iterator it = result.begin(); it != result.end(); it++) {
        cout << *it << " ";
    }

    return 0;
}