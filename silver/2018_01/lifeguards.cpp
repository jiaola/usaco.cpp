#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("lifeguards");
    int N;
    cin >> N;
    int lifeguards[N][2];
    for (int i = 0; i < N; ++i) {
        cin >> lifeguards[i][0] >> lifeguards[i][1];
    }
    int m = 0, m_i = 0;
    for (int i =0; i < N; ++i) {
        m_i = 0;
        for (int k = 0; k < 1000; ++k) {
            for (int j = 0; j < N; ++j) {
                if (i == j) {
                    continue;
                }
                if (lifeguards[j][0] <= k && lifeguards[j][1] > k) {
                    m_i++;
                    break;
                }
            }
        }
        m = max(m, m_i);
    }
    cout << m << endl;
    return 0;
}