#include <iostream>
using namespace std;
 
int n, ans = 1;
int minV = 64, sum = 64;

int main() {
    
    cin >> n;
 
    
    while (sum > n) {
        minV = minV / 2;
        if(sum - minV >= n) {
            sum -= minV;
        } else {
            ans++;
        }
    }
 
    cout << ans;
    return 0;
}
