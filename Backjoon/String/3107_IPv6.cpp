/*
    3107 - IPv6
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string address, ans;
vector<string> addr;
int colonCnt;
bool isCompact;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> address;

    int prev = 0, curr = address.find(":");
    while (curr != string::npos) {
        string subStr = address.substr(prev, curr - prev);
        
        addr.push_back(subStr);
        colonCnt++;

        prev = curr + 1;
        curr = address.find(":", prev);
    }
    addr.push_back(address.substr(prev, curr - prev));

    if (address.find("::") != string::npos)
        isCompact = true;

    if (addr.size() != 8) {
        vector<string> tmp;
        for (int i = 0; i < addr.size(); i++) {
            if (addr[i].size() == 0 && isCompact) {
                for (int j = 0; j < 9 - addr.size(); j++)
                    tmp.push_back("0000");

                isCompact = false;
            }
            else
                tmp.push_back(addr[i]);
        }
        addr = tmp;
    }

    for (int i = 0; i < 8; i++) {
        if (addr[i].size() < 4) {
            string tmp;
            
            for (int j = 0; j < 4 - addr[i].size(); j++)
                tmp += "0";

            tmp += addr[i];

            ans += tmp;
        }
        else
            ans += addr[i];
    }

    for (int i = 4; i < 35; i += 5)
        ans.insert(i, ":");

    cout << ans;

    return 0;
}