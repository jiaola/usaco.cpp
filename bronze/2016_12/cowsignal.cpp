#include <iostream>
#include <cstdio>
using namespace std;

void setIO(string name = "") { // name is nonempty for USACO file I/O
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main(void) {
    setIO("cowsignal");
    int M, N, K;
    cin >> M >> N >> K;
    for (int i = 0; i < M; ++i) {
        string s;
        cin >> s;
        for (int k1 = 0; k1 < K; ++k1) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < K; ++k) {
                    cout << s[j];
                }
            }
            cout << endl;
        }
    }
}

