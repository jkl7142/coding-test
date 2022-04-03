/*
    1431 - �ø��� ��ȣ
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

#define MAX_N 51

int n;
string str;
vector<string> serials;

bool cmp (string& a, string& b) {
    int aLen = a.size();
    int bLen = b.size();
    int aSum = 0, bSum = 0;

    // 1. ���̰� ª�� ��
    if (aLen != bLen)
        return aLen < bLen;

    // 2. ������ ���� ���� ��
    for (int i = 0; i < aLen; i++) {
        if (isdigit(a[i]))
            aSum += a[i] - '0';
    }
    for (int i = 0; i < bLen; i++) {
        if (isdigit(b[i]))
            bSum += b[i] - '0';
    }

    if (aSum != bSum)
        return aSum < bSum;

    // 3. ���� ��
    return a < b;
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> str;
        serials.push_back(str);
    }

    sort(serials.begin(), serials.end(), cmp);

    for (string s : serials)
        cout << s << "\n";

    return 0;
}