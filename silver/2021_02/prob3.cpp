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

int main() {
    setIO("prob3");
    int N;
    cin >> N;
    int val;
    int b[N][N];
    vector<pair<int, int>> valid;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> b[i][j];
            if (b[i][j] >= 100) {
                valid.push_back(make_pair(i, j));
            }
        }
    }
    for (int i = 0; i < N; ++i) {

    }
    cout << valid.size();
    return 0;
}