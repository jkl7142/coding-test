/*
    1026 - 보물
*/

#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N 51

int n, ans;
int A[MAX_N];
int B[MAX_N];

int main() {

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];

    sort(A, A + n);
    sort(B, B + n);

    for (int i = 0; i < n; i++)
        ans += A[i] * B[n - i - 1];

    cout << ans;

    return 0;
}