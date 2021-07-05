#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (name.size()) {
        freopen((name+".in").c_str(), "r", stdin);
    }
}

int main(void) {
    setIO("a");
    int t;
    cin >> t;
    int n, k, s;
    for (int i = 0; i < t; ++i) {
        cin >> n >> k;
        if (n % k == 0) {
            s = n;
        } else {
            s = (n / k + 1) * k;
        }
        if (s % n == 0) {
            cout << s / n << "\n";
        } else {
            cout << s / n + 1 << "\n";
        }

    }
    return 0;
}