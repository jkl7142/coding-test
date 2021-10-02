/*
*   3053 - 택시 기하학
*   두 점 T1(x1,y1), T2(x2,y2) 사이의 거리
*   D(T1,T2) = |x1-x2| + |y1-y2|
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double euclidean(int r) {
    double dr = static_cast<double>(r);
    return dr * dr * M_PI;
}

double taxicab(int r) {
    double dr = static_cast<double>(r);
    return dr * dr * 2.000000;
}

int main() {

    int r;
    cin >> r;
    
    cout << fixed;
    cout << setprecision(6);
    cout << euclidean(r) << "\n";
    cout << taxicab(r) << "\n";

    return 0;
}