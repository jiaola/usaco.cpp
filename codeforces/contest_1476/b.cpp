#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
    }
}

int main(void) {
//    setIO("b");
    int t;
    cin >> t;
    int n, k;
    for (int i = 0; i < t; ++i) {
        long long m = 0;
        cin >> n >> k;
        long long pi;
        cin >> pi;
        long long current = pi;
        double inf;
        for (int j = 1; j < n; ++j) {
            cin >> pi;
            inf = (double) pi / current;
            if (inf * 100.0 > k) {
                long long x = ceil((100 * pi - k * current) / (double)k);
                m += x;
                current += x;
            }
            current = current + pi;
        }
        cout << m << endl;
    }


    return 0;
}