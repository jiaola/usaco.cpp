#include <iostream>
#include <algorithm>


using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        // freopen((name+".out").c_str(), "r", stdout);
    }
}

long long g[1000][1000];
int N;


int main(void) {
    setIO("");

    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> g[i][j];
        }
    }
    long long ans1 = 0;
    for (int i = 0; i < N; ++i) {
        long long s[2];
        s[0] = 0;
        s[1] = 0;
        for (int j = 0; j < N; ++j) {
            s[j % 2] += g[i][j];
        }
        ans1 += max(s[0], s[1]);
    }
    long long ans2 = 0;
    for (int i = 0; i < N; ++i) {
        long long s[2];
        s[0] = 0;
        s[1] = 0;
        for (int j = 0; j < N; ++j) {
            s[j % 2] += g[j][i];
        }
        ans2 += max(s[0], s[1]);
    }

    cout << max(ans1, ans2) << "\n";
}