#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
//        freopen((name+".out").c_str(), "w", stdout);
    }
}

const int S = 1000;
int b[S][S];
int c[S][S];


int update(int x, int y) {
    int ret = 0;
    if (x < 0 || x >= S || y < 0 || y >= S) {
        return ret;
    }
    if (c[x][y] == 2) {
        ret = 1;
    } else if (c[x][y] == 3) {
        ret = -1;
    }
    c[x][y]++;
    return ret;
}


int main() {
    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            b[i][j] = 0;
            c[i][j] = 0;
        }
    }
    setIO("prob1");
    int N;
    cin >> N;
    int total = 0;
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        b[x][y] = 1;
        total += update(x-1, y);
        total += update(x, y-1);
        total += update(x+1, y);
        total += update(x, y+1);
        cout << total << "\n";
    }

}