/*
*   3036¹ø - ¸µ
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int GCD(int a, int b) {
    int answer = 0;

    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }

    return answer = a;
}

vector<string> solution(vector<int> radiuses) {
    vector<string> result;

    int f_radius = radiuses[0];
    for (int i = 1; i < radiuses.size(); i++) {
        int gcd = GCD(f_radius, radiuses[i]);
        string fraction = to_string(f_radius / gcd) + "/"
                        + to_string(radiuses[i] / gcd);

        result.push_back(fraction);
    }

    return result;
}

int main() {

    int n;
    cin >> n;
    vector<int> radiuses;
    
    for (int i = 0; i < n; i++) {
        int radius;
        cin >> radius;

        radiuses.push_back(radius);
    }

    for (auto f : solution(radiuses)) {
        cout << f << "\n";
    }

    return 0;
}