#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        // freopen((name+".out").c_str(), "w", stdout);
    }
}

int N;

struct move {
    char letter;
    int i;
    int j;
};

string maze[25][25];
int board[3][3] {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
};

bool check(int b[3][3]) {
    // rows
    for (int i = 0; i < 3; ++i) {
        int p = b[i][0] * b[i][1] * b[i][2];
        if (p == -1 && b[i][1] == 1) {
            return true;
        }
        p = b[0][i] * b[1][i] * b[2][i];
        if (p == -1 && b[1][i] == 1) {
            return true;
        }
    }
    if (b[1][1] == 1) {
        if (b[0][0] * b[1][1] * b[2][2] == -1 || b[0][2] * b[1][1] * b[2][0] == -1) {
            return true;
        }
    }
    return false;
}

void solve() {

}


int main() {
    setIO("prob1");
    cin >> N;
    string s;
    for (int i = 0 ; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            char a, b, c;
            cin >> a >> b >> c;
            if (a == '#') {
                maze[i][j] = "#";
            } else if (a == '.') {
                maze[i][j] = ".";
            } else {
                s = "";
                maze[i][j] = s + a + b + c;
            }
        }
    }
    cout << maze[1][1] << "\n";
    cout << check(board) << "\n";
    return 0;
}