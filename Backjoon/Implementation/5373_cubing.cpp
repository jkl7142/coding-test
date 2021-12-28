/*
*   5373¹ø - Å¥ºù
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> cube;

vector<vector<string>> start = {{"www", "www", "www"},
                                {"yyy", "yyy", "yyy"},
                                {"rrr", "rrr", "rrr"},
                                {"ooo", "ooo", "ooo"},
                                {"ggg", "ggg", "ggg"},
                                {"bbb", "bbb", "bbb"}};

void rotate(vector<string>& side, char direction) {
    vector<string> tmp(3, "000");
    if (direction == '+') {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tmp[i][j] = side[3 - j - 1][i];
            }
        }
    }
    else {  // '-'
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tmp[i][j] = side[j][3 - i - 1];
            }
        }
    }

    side = tmp;
}

void turnUp(char direction) {
    string tmp = cube[2][0];

    if (direction == '+') {
        for (int i = 0; i < 3; i++) {
            cube[2][0][i] = cube[5][2 - i][0];
            cube[5][2 - i][0] = cube[3][2][2 - i];
            cube[3][2][2 - i] = cube[4][i][2];
            cube[4][i][2] = tmp[i];
        }
    }
    else {  // '-'
        for (int i = 0; i < 3; i++) {
            cube[2][0][i] = cube[4][i][2];
            cube[4][i][2] = cube[3][2][2 - i];
            cube[3][2][2 - i] = cube[5][2 - i][0];
            cube[5][2 - i][0] = tmp[i];
        }
    }

    rotate(cube[0], direction);
}

void turnDown(char direction) {
    string tmp = cube[2][2];

    if (direction == '+') {    
        for (int i = 0; i < 3; i++) {
            cube[2][2][i] = cube[4][i][0];
            cube[4][i][0] = cube[3][0][2 - i];
            cube[3][0][2 - i] = cube[5][2 - i][2];
            cube[5][2 - i][2] = tmp[i];
        }
    }
    else {  // '-'
        for (int i = 0; i < 3; i++) {
            cube[2][2][i] = cube[5][2 - i][2];
            cube[5][2 - i][2] = cube[3][0][2 - i];
            cube[3][0][2 - i] = cube[4][i][0];
            cube[4][i][0] = tmp[i];
        }
    }

    rotate(cube[1], direction);
}

void turnFront(char direction) {
    string tmp = cube[0][2];

    if (direction == '+') {
        for (int i = 0; i < 3; i++) {
            cube[0][2][i] = cube[4][2][i];
            cube[4][2][i] = cube[1][0][2 - i];
            cube[1][0][2 - i] = cube[5][2][i];
            cube[5][2][i] = tmp[i];
        }
    }
    else {  // '-'
        for (int i = 0; i < 3; i++) {
            cube[0][2][i] = cube[5][2][i];
            cube[5][2][i] = cube[1][0][2 - i];
            cube[1][0][2 - i] = cube[4][2][i];
            cube[4][2][i] = tmp[i];
        }
    }

    rotate(cube[2], direction);
}

void turnBack(char direction) {
    string tmp = cube[0][0];

    if (direction == '+') {
        for (int i = 0; i < 3; i++) {
            cube[0][0][i] = cube[5][0][i];
            cube[5][0][i] = cube[1][2][2 - i];
            cube[1][2][2 - i] = cube[4][0][i];
            cube[4][0][i] = tmp[i];
        }
    }
    else {  // '-'
        for (int i = 0; i < 3; i++) {
            cube[0][0][i] = cube[4][0][i];
            cube[4][0][i] = cube[1][2][2 - i];
            cube[1][2][2 - i] = cube[5][0][i];
            cube[5][0][i] = tmp[i];
        }
    }

    rotate(cube[3], direction);
}

void turnLeft(char direction) {
    string tmp;
    tmp += cube[0][0][0];
    tmp += cube[0][1][0];
    tmp += cube[0][2][0];

    if (direction == '+') {
        for (int i = 0; i < 3; i++) {
            cube[0][i][0] = cube[3][i][0];
            cube[3][i][0] = cube[1][i][0];
            cube[1][i][0] = cube[2][i][0];
            cube[2][i][0] = tmp[i];
        }
    }
    else {  // '-'
        for (int i = 0; i < 3; i++) {
            cube[0][i][0] = cube[2][i][0];
            cube[2][i][0] = cube[1][i][0];
            cube[1][i][0] = cube[3][i][0];
            cube[3][i][0] = tmp[i];
        }
    }

    rotate(cube[4], direction);
}

void turnRight(char direction) {
    string tmp;
    tmp += cube[0][0][2];
    tmp += cube[0][1][2];
    tmp += cube[0][2][2];

    if (direction == '+') {
        for (int i = 0; i < 3; i++) {
            cube[0][i][2] = cube[2][i][2];
            cube[2][i][2] = cube[1][i][2];
            cube[1][i][2] = cube[3][i][2];
            cube[3][i][2] = tmp[i];
        }
    }
    else {  // '-'
        for (int i = 0; i < 3; i++) {
            cube[0][i][2] = cube[3][i][2];
            cube[3][i][2] = cube[1][i][2];
            cube[1][i][2] = cube[2][i][2];
            cube[2][i][2] = tmp[i];
        }
    }

    rotate(cube[5], direction);
}

void printCube() {
    for (int i = 0; i < 3; i++) {
        cout << cube[0][i] << "\n";
    }
}

void solution(vector<string> move) {
    int turns = move.size();
    
    for (int i = 0; i < turns; i++) {
        string m = move[i];

        switch(m[0]) {
            case 'U':
                turnUp(m[1]);
                break;
            case 'D':
                turnDown(m[1]);
                break;
            case 'F':
                turnFront(m[1]);
                break;
            case 'B':
                turnBack(m[1]);
                break;
            case 'L':
                turnLeft(m[1]);
                break;
            default:
                turnRight(m[1]);
                break;
        }
    }

    printCube();
}

int main() {

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cube = start;
        int n;
        cin >> n;
        vector<string> move;

        for (int j = 0; j < n; j++) {
            string m;
            cin >> m;

            move.push_back(m);
        }

        solution(move);
    }

    return 0;
}