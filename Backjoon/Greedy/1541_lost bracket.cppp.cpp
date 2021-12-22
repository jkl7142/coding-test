/*
*   1541¹ø - ÀÒ¾î¹ö¸° °ýÈ£
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void parse(string str, vector<string>& nums, string del) {
    size_t prev = 0, curr;

    curr = str.find(del);
    while (curr != string::npos) {
        string subStr = str.substr(prev, curr - prev);
        nums.push_back(subStr);
        prev = curr + 1;

        curr = str.find(del, prev);
    }
    nums.push_back(str.substr(prev, curr - prev));
}

void addString(vector<string>& nums, string del) {

    for (int i = 0; i < nums.size(); i++) {
        size_t prev = 0, curr;
        int temp = 0;

        curr = nums[i].find(del);
        while (curr != string::npos) {
            string num = nums[i].substr(prev, curr - prev);
            temp += stoi(num);
            prev = curr + 1;

            curr = nums[i].find(del, prev);
        }
        if (prev)
            temp += stoi(nums[i].substr(prev, curr - prev));

        if (temp)
            nums[i] = to_string(temp);
    }
}

int solution(string exp) {
    int answer = 0;
    vector<string> nums;

    parse(exp, nums, "-");
    addString(nums, "+");

    answer = stoi(nums[0]);

    for (int i = 1; i < nums.size(); i++) {
        answer -= stoi(nums[i]);
    }

    return answer;
}

int main() {

    string exp;
    cin >> exp;

    cout << solution(exp) << "\n";
}